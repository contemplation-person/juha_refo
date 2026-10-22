#!/usr/bin/env bash
#
# moulinette — Rust Piscine 채점기
#
# 사용법:
#   ./grademe.sh module00          모듈 전체 채점 (첫 실패에서 중단)
#   ./grademe.sh module00 ex03     과제 하나만 채점
#
# 실패 원인은 rendu/deepthought 에 남는다.
#
set -u

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TESTS="$ROOT/moulinette"
RENDU="${PISCINE_RENDU:-$ROOT/rendu}"
WORK="${PISCINE_WORK:-$ROOT/.work}"
TRACE="$RENDU/deepthought"
TIME_LIMIT=10

if [[ -t 1 ]]; then
  GREEN=$'\e[32m' RED=$'\e[31m' GRAY=$'\e[90m' BOLD=$'\e[1m' RESET=$'\e[0m'
else
  GREEN='' RED='' GRAY='' BOLD='' RESET=''
fi

usage() {
  echo "사용법: $0 <module> [exNN]"
  echo "모듈:"
  for d in "$TESTS"/module*/; do echo "  $(basename "$d")"; done
  exit 2
}

[[ $# -ge 1 && $# -le 2 ]] || usage
MODULE="$1"
ONLY="${2:-}"
[[ -d "$TESTS/$MODULE" ]] || { echo "없는 모듈: $MODULE"; usage; }
if [[ -n $ONLY && ! -d "$TESTS/$MODULE/$ONLY" ]]; then
  echo "없는 과제: $MODULE/$ONLY"
  exit 2
fi

mkdir -p "$RENDU"
: > "$TRACE"

trace() { printf '%s\n' "$*" >> "$TRACE"; }

# grade_ex <exNN>
# 통과하면 0. 실패하면 REASON 을 채우고 1.
grade_ex() {
  local ex="$1"
  local t="$TESTS/$MODULE/$ex"
  local s="$RENDU/$MODULE/$ex"
  local w="$WORK/$MODULE/$ex"
  local KIND="" NAME="$ex"
  local -a FORBIDDEN=()
  # shellcheck source=/dev/null
  source "$t/meta"

  trace "===== $MODULE/$ex ====="

  # 1. 제출물 형태
  if [[ ! -f "$s/Cargo.toml" ]]; then
    REASON="제출물 없음: $MODULE/$ex/Cargo.toml"
    return 1
  fi
  local entry="src/lib.rs"
  [[ $KIND == bin ]] && entry="src/main.rs"
  if [[ ! -f "$s/$entry" ]]; then
    REASON="$entry 없음 (이 과제는 $KIND)"
    return 1
  fi

  local name
  name=$(sed -n 's/^[[:space:]]*name[[:space:]]*=[[:space:]]*"\([^"]*\)".*/\1/p' "$s/Cargo.toml" | head -n1)
  if [[ $name != "$NAME" ]]; then
    REASON="패키지 이름은 \"$NAME\" 이어야 함 (현재: \"$name\")"
    return 1
  fi

  if awk '/^[[:space:]]*\[/ { sec = $0; next }
          sec ~ /dependencies/ && NF && $1 !~ /^#/ { found = 1 }
          END { exit !found }' "$s/Cargo.toml"; then
    REASON="외부 크레이트 금지 ([dependencies] 는 비워 둘 것)"
    return 1
  fi

  # 2. 금지 항목 (주석까지 검사한다)
  local hit p
  hit=$(grep -rnE '\bunsafe\b' "$s/src")
  if [[ -n $hit ]]; then
    trace "$hit"
    REASON="unsafe 금지"
    return 1
  fi
  for p in "${FORBIDDEN[@]}"; do
    hit=$(grep -rnE -- "$p" "$s/src")
    if [[ -n $hit ]]; then
      trace "금지 패턴 /$p/ 발견:"
      trace "$hit"
      REASON="금지 항목 사용: $p"
      return 1
    fi
  done

  # 3. norm — 작업 사본에서 fmt, clippy
  mkdir -p "$w"
  # -c: 내용이 바뀐 파일만 새 mtime 으로 복사한다. 옛 mtime 을 보존하면 cargo 가 재빌드를 건너뛴다.
  rsync -rlc --delete --exclude /target --exclude /tests --exclude .git "$s/" "$w/"
  rm -rf "$w/tests"

  if ! (cd "$w" && cargo fmt --check -- --color never) >> "$TRACE" 2>&1; then
    REASON="norm: cargo fmt 미통과"
    return 1
  fi
  if ! (cd "$w" && cargo clippy -q --color never -- -D warnings) >> "$TRACE" 2>&1; then
    REASON="컴파일 에러 또는 clippy 경고"
    return 1
  fi

  # 4-a. 라이브러리: 숨은 테스트를 붙여 실행
  if [[ $KIND == lib ]]; then
    mkdir -p "$w/tests"
    cp "$t/tests.rs" "$w/tests/moulinette.rs"
    if ! (cd "$w" && cargo test -q --color never --test moulinette --no-run) >> "$TRACE" 2>&1; then
      REASON="채점 테스트 컴파일 실패 (이름·시그니처 확인)"
      return 1
    fi
    (cd "$w" && timeout "$TIME_LIMIT" cargo test -q --color never --test moulinette) >> "$TRACE" 2>&1
    local rc=$?
    if ((rc == 124)); then
      REASON="시간 초과 (${TIME_LIMIT}초)"
      return 1
    fi
    if ((rc != 0)); then
      REASON="테스트 실패"
      return 1
    fi
    return 0
  fi

  # 4-b. 실행 파일: 케이스마다 실행해 출력 비교
  if ! (cd "$w" && cargo build -q --color never) >> "$TRACE" 2>&1; then
    REASON="빌드 실패"
    return 1
  fi
  local bin="$w/target/debug/$NAME"
  local c id
  for c in "$t"/cases/*/; do
    c="${c%/}"
    id="$(basename "$c")"
    local -a args=()
    [[ -f "$c/args" ]] && mapfile -t args < "$c/args"
    local in=/dev/null
    [[ -f "$c/stdin" ]] && in="$c/stdin"
    local want_code=0
    [[ -f "$c/code" ]] && want_code=$(< "$c/code")

    (cd "$c" && timeout "$TIME_LIMIT" "$bin" "${args[@]}" < "$in" > "$w/.out" 2> "$w/.err")
    local rc=$?

    if ((rc == 124)); then
      trace "[case $id] 시간 초과"
      REASON="시간 초과 (case $id)"
      return 1
    fi
    if ((rc != want_code)); then
      trace "[case $id] 인자: ${args[*]:-(없음)}"
      trace "[case $id] 종료 코드 기대 $want_code, 실제 $rc"
      trace "--- stderr ---"
      head -n 20 "$w/.err" >> "$TRACE"
      REASON="종료 코드 다름 (case $id)"
      return 1
    fi
    if ! cmp -s "$c/stdout" "$w/.out"; then
      trace "[case $id] 인자: ${args[*]:-(없음)}"
      trace "[case $id] stdout 다름 (< 기대, > 실제)"
      diff "$c/stdout" "$w/.out" | head -n 40 >> "$TRACE"
      REASON="출력 다름 (case $id)"
      return 1
    fi
    if [[ -f "$c/stderr" ]] && ! cmp -s "$c/stderr" "$w/.err"; then
      trace "[case $id] 인자: ${args[*]:-(없음)}"
      trace "[case $id] stderr 다름 (< 기대, > 실제)"
      diff "$c/stderr" "$w/.err" | head -n 40 >> "$TRACE"
      REASON="에러 출력 다름 (case $id)"
      return 1
    fi
  done
  return 0
}

EXES=()
if [[ -n $ONLY ]]; then
  EXES=("$ONLY")
else
  for d in "$TESTS/$MODULE"/ex*/; do EXES+=("$(basename "$d")"); done
fi

echo "${BOLD}$MODULE${RESET}"
passed=0
stopped=0
for ex in "${EXES[@]}"; do
  if ((stopped)); then
    echo "  $ex  ${GRAY}-- 검사 안 함${RESET}"
    continue
  fi
  REASON=""
  printf '  %s  ' "$ex"
  if grade_ex "$ex"; then
    echo "${GREEN}OK${RESET}"
    trace "OK"
    passed=$((passed + 1))
  else
    echo "${RED}KO${RESET}  $REASON"
    trace "KO: $REASON"
    stopped=1
  fi
done

total=${#EXES[@]}
echo
if ((passed == total)); then
  echo "${GREEN}${BOLD}통과 $passed/$total${RESET}"
  exit 0
fi
echo "${RED}${BOLD}통과 $passed/$total${RESET}  기록: ${TRACE#"$ROOT"/}"
exit 1

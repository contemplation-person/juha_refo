# 채점 규칙 (moulinette)

`grademe.sh` 가 무엇을, 어떤 순서로, 얼마나 엄격하게 보는지 정리한 문서다.

한 줄로 줄이면 이렇다. **제출 폴더를 복사해 5단계로 검사하고, 처음 틀린 곳에서 멈춘다.**

---

## 1. 실행

```sh
./grademe.sh module03          # 모듈 전체. 첫 실패에서 중단
./grademe.sh module03 ex04     # 과제 하나만. 앞 과제와 상관없이 본다
```

| 종료 코드 | 뜻 |
|-----------|----|
| `0` | 검사한 과제 전부 통과 |
| `1` | 하나 이상 실패 |
| `2` | 사용법 오류 (없는 모듈·과제 이름) |

환경 변수 두 개로 경로를 바꿀 수 있다. 평소에는 쓸 일이 없다.

| 변수 | 기본값 | 용도 |
|------|--------|------|
| `PISCINE_RENDU` | `rendu/` | 채점할 제출 폴더 |
| `PISCINE_WORK` | `.work/` | 검사용 사본을 두는 곳 |

---

## 2. 검사 순서

과제 하나는 아래 5단계를 순서대로 지난다. 한 단계라도 걸리면 그 과제는 KO 다. 뒤 단계는 보지 않는다.

| 단계 | 검사 | 기준 | KO 메시지 |
|------|------|------|-----------|
| 1 | 제출물 형태 | `Cargo.toml` 이 있다. 라이브러리 과제는 `src/lib.rs`, 실행 파일 과제는 `src/main.rs` 가 있다 | `제출물 없음`, `src/lib.rs 없음` |
| 1 | 패키지 이름 | `Cargo.toml` 의 첫 `name = "..."` 이 과제 폴더 이름과 같다 (BSQ 만 `bsq`) | `패키지 이름은 "ex03" 이어야 함` |
| 1 | 외부 크레이트 | 이름에 `dependencies` 가 들어간 섹션이 모두 비어 있다 | `외부 크레이트 금지` |
| 2 | `unsafe` | `src/` 아래 어디에도 단어 `unsafe` 가 없다 | `unsafe 금지` |
| 2 | 과제별 금지 항목 | `src/` 아래 어디에도 금지 패턴이 없다 (6장 표) | `금지 항목 사용: <패턴>` |
| 3 | 모양 | `cargo fmt --check` 통과 | `norm: cargo fmt 미통과` |
| 4 | 컴파일과 clippy | `cargo clippy -- -D warnings` 통과. 경고 하나도 실패다 | `컴파일 에러 또는 clippy 경고` |
| 5 | 동작 | 숨은 테스트 통과 (3장, 4장) | `테스트 실패`, `출력 다름` 등 |

외부 크레이트 검사는 `[dependencies]` 만 보지 않는다. `[dev-dependencies]`, `[build-dependencies]`, `[target.'...'.dependencies]` 도 같이 본다. 빈 줄과 `#` 주석 줄은 괜찮다.

3단계부터는 제출 폴더가 아니라 `.work/` 의 사본에서 돈다. 사본을 만들 때 `target/`, `tests/`, `.git/` 은 복사하지 않는다. 직접 만든 `tests/` 폴더는 채점에 쓰이지 않는다는 뜻이다.

### 첫 실패에서 멈춘다

모듈 전체를 채점하면 ex00 부터 차례로 본다. 하나가 KO 면 나머지는 `-- 검사 안 함` 으로 표시하고 끝낸다. 42 의 채점 방식 그대로다. 앞 과제를 비워 두면 뒤 과제를 잘 풀어도 점수가 없다.

과제 하나만 지정하면 이 규칙은 적용되지 않는다. 연습할 때는 `./grademe.sh module03 ex04` 처럼 돌린다.

---

## 3. 라이브러리 과제의 동작 검사

대부분의 과제가 이 방식이다. 학생은 함수·구조체·트레이트를 `src/lib.rs` 에 쓴다. 채점기는 숨은 테스트 파일을 붙여서 돌린다.

```
moulinette/module03/ex02/tests.rs  →  .work/module03/ex02/tests/moulinette.rs
```

1. `cargo test --test moulinette --no-run` 으로 테스트를 컴파일한다. 시간 제한은 없다.
2. `cargo test --test moulinette` 로 실행한다. 여기에 10초 제한이 걸린다.

테스트 파일은 `use ex02::ft_split;` 처럼 크레이트 이름으로 함수를 부른다. 그래서 1단계의 패키지 이름 검사가 필요하다.

1번에서 실패하면 `채점 테스트 컴파일 실패` 가 뜬다. 함수 이름, 매개변수 타입, 반환 타입, 수명 표기, `pub` 누락이 과제와 다르다는 뜻이다. 정확한 컴파일 에러는 `deepthought` 에 있다.

`src/lib.rs` 안의 `#[cfg(test)]` 테스트는 채점에 쓰이지 않는다. 직접 확인하는 용도로만 쓴다.

---

## 4. 실행 파일 과제의 동작 검사

해당 과제는 다섯 개다: module00 ex00·ex05·ex06, module04 ex03, module09 ex00.

`cargo build` 로 만든 프로그램을 케이스마다 실행해 결과를 비교한다. 케이스 하나는 폴더 하나다.

```
moulinette/module04/ex03/cases/03/
├── args       인자. 한 줄이 인자 하나
├── stdin      표준 입력 (없으면 빈 입력)
├── stdout     기대하는 표준 출력
├── stderr     기대하는 에러 출력 (있을 때만 비교)
├── code       기대하는 종료 코드 (없으면 0)
└── *.txt 등   프로그램이 읽을 파일
```

| 항목 | 규칙 |
|------|------|
| 실행 위치 | 케이스 폴더 안에서 실행한다. 인자 `hello.txt` 는 그 폴더의 파일이다 |
| 인자 | `args` 의 줄마다 인자 하나다. 줄 안의 공백은 그대로 유지된다 |
| 표준 출력 | 바이트 단위로 같아야 한다. 마지막 줄바꿈 하나, 공백 하나도 틀리면 KO |
| 에러 출력 | `stderr` 파일이 있는 케이스만 비교한다. 비교할 때는 바이트 단위다 |
| 종료 코드 | 정확히 같아야 한다. panic 은 101 이라 기대값과 다르게 된다 |
| 시간 | 케이스마다 10초 |

BSQ 는 34개 케이스 전부 `stderr` 를 비교한다. 정상 지도에서 디버그 출력을 `eprintln!` 으로 남기면 KO 다.

---

## 5. 시간 제한과 빌드 모드

제한은 **10초**다. 넘으면 프로세스를 통째로 끄고 `시간 초과` 로 KO 처리한다.

| 과제 종류 | 10초에 들어가는 것 |
|-----------|-------------------|
| 라이브러리 | 테스트 실행 전체 (cargo 기동 포함, 컴파일 제외) |
| 실행 파일 | 케이스 하나의 실행 |

빌드는 **디버그 모드**다. 이 사실이 두 가지 결과를 낳는다.

- 정수가 넘치면(overflow) 조용히 틀리지 않고 panic 으로 멈춘다. 테스트는 이를 일부러 노린다.
- 릴리스 빌드보다 수십 배 느리다. 비효율적인 알고리즘은 여기서 걸러진다. 대표적인 예가 `is_prime`, `fibonacci`, BSQ 의 큰 지도다.

무한 루프, 교착 상태(deadlock), 닫히지 않은 채널도 시간 초과로 나타난다.

---

## 6. 과제별 금지 항목

금지 항목은 `grep -E` 로 찾는 글자 패턴이다. 문법을 이해하는 검사가 아니다. 그래서 **주석과 문자열 안의 글자도 걸린다.** 예를 들어 module06 ex04 에서 주석에 영어 단어 `for` 를 쓰면 KO 다.

`\b` 는 단어 경계다. `\bmax\(` 는 `max(` 와 `.max(` 를 잡는다. `max_of_three(` 는 잡지 않는다.

| 과제 | 패턴 | 막는 것 |
|------|------|---------|
| module00 ex01 | `\bmax\(` `cmp::` | 모든 `max` 호출, `std::cmp` |
| module01 ex01 | `\.len\(` `\.count\(` | 길이를 바로 얻는 메서드 |
| module01 ex02 | `\.r?split...\(` `\.r?find\(` `trim` `\.position\(` | split 계열 전부, `find`, `rfind`, `trim` 계열, `position` |
| module01 ex03 | `\brev\(` | `.rev()` |
| module01 ex05 | `\.join\(` `concat` | `join`, `concat` |
| module02 ex02 | `3\.14` | π 를 손으로 적기 |
| module02 ex03 | `checked_` `overflowing_` `wrapping_` `\.position\(` `\.r?find\(` `\.contains\(` | 안전 산술 메서드, 검색 메서드 |
| module03 ex00 | `\.collect` `\.to_vec` `\bextend` `vec!\[[^]]` | 반복자 수집, 값이 든 `vec![..]` (빈 `vec![]` 는 허용) |
| module03 ex01 | `\.sort` `BinaryHeap` `BTree` | 모든 정렬 메서드, 정렬된 컬렉션 |
| module03 ex02 | `[.:]split` `\.lines\(` | split 계열, `lines` |
| module03 ex05 | `from_str_radix` | 진법 변환 함수 |
| module04 ex02 | `\bmatch\b` `\.unwrap` `\.expect\(` | `match`, `unwrap` 계열, `expect` — `?` 만 쓰게 한다 |
| module04 ex04 | `\.parse` `from_str` `\bi64\b` `\bi128\b` `\bu64\b` `\bu128\b` | 표준 파싱, 더 큰 정수 타입으로 피하기 |
| module04 ex06 | `map_err` `\.unwrap` `\.expect\(` | `From` 구현 대신 쓰는 지름길 |
| module05 ex00 | `\bmax(_by(_key)?)?\(` `cmp::` `\.(fold\|reduce)\(` | `max` 계열, `fold`, `reduce` |
| module06 ex00 | `\.(map\|for_each\|filter\|...\|extend)\(` | 반복자 어댑터 전부 — 반복문으로 직접 |
| module06 ex01 | 위와 같음 + `is_sorted...` | 반복자 어댑터, `is_sorted` 계열 |
| module06 ex04 | `\bfor\b` `\bwhile\b` `\bloop\b` | 반복문 전부 — 반복자로만 |
| module06 ex06 | `\.(windows\|tuple_windows\|zip)\(` | 이미 있는 짝짓기 도구 |
| module07 ex02, ex03 | `\bVec\b` `vec!` `VecDeque` `LinkedList` `collections` | 표준 컬렉션 — 리스트를 직접 만든다 |
| module07 ex04 | `BTree` `collections` `\.sort` | 표준 트리, 정렬 |
| module08 ex03 | `Atomic` `mpsc` `\bscope\b` | 원자 타입, 채널, scoped thread — `Arc<Mutex>` 만 |
| module08 ex04 | `\bscope\b` | scoped thread — 스레드 풀을 직접 관리 |

표에 없는 과제의 금지 항목은 `unsafe` 와 외부 크레이트뿐이다. 정확한 패턴은 각 과제의 `moulinette/<module>/<ex>/meta` 에 있다.

---

## 7. 자주 걸리는 clippy 경고

4단계는 clippy 기본 경고를 전부 에러로 다룬다. Rust 1.98 기준으로 아래가 특히 자주 걸린다.

| 경고 | 걸리는 코드 | 고치는 법 |
|------|------------|-----------|
| `manual_is_multiple_of` | `n % 2 == 0` | `n.is_multiple_of(2)` |
| `new_without_default` | 인자 없는 `pub fn new()` 만 있음 | `Default` 도 구현 (`#[derive(Default)]`) |
| `len_without_is_empty` | `pub fn len()` 만 있음 | `pub fn is_empty()` 도 만든다 |
| `manual_swap` | 임시 변수로 두 값 교환 | `std::mem::swap` |
| `redundant_slicing` | `&s[..]` 를 그대로 반환 | `s` 를 그대로 반환 |
| `needless_range_loop` | `for i in 0..v.len()` 로 `v[i]` 만 씀 | `for x in &v` 또는 `.iter().enumerate()` |

경고 메시지에 `help:` 로 고치는 법이 같이 나온다. `deepthought` 에서 확인한다.

clippy 는 라이브러리와 실행 파일 코드만 검사한다. `#[cfg(test)]` 안의 코드는 보지 않는다. `cargo fmt --check` 는 테스트 코드까지 포함해 `src/` 전체를 본다.

---

## 8. 기록 파일 `rendu/deepthought`

채점할 때마다 처음부터 다시 쓴다. 과제마다 `===== module03/ex02 =====` 로 구분하고, 끝에 `OK` 또는 `KO: <이유>` 를 남긴다.

| 실패 단계 | 남는 내용 |
|-----------|-----------|
| 금지 항목 | 걸린 파일, 줄 번호, 그 줄 |
| fmt | `cargo fmt` 가 바꾸려는 diff |
| clippy·컴파일 | 컴파일러 메시지 전체 |
| 라이브러리 테스트 | 실패한 테스트 이름, panic 메시지, 기대값과 실제값 |
| 실행 파일 | 케이스 번호, 인자, 출력 diff (`<` 기대, `>` 실제, 앞 40줄), 종료 코드, stderr 앞 20줄 |

---

## 9. 과제를 추가하거나 고칠 때

과제 하나는 `moulinette/<module>/<exNN>/` 폴더 하나다. 폴더 이름순(ex00, ex01, …)으로 채점한다.

`meta` 는 bash 문법으로 쓴다. 채점기가 `source` 로 읽는다.

```sh
KIND=lib                              # lib 또는 bin
NAME=bsq                              # 선택. 기본값은 폴더 이름(exNN)
FORBIDDEN=('\.sort' 'BinaryHeap')     # 선택. grep -E 패턴 목록
```

| 종류 | 필요한 파일 |
|------|-------------|
| `lib` | `tests.rs` — `use <패키지이름>::...;` 로 시작하는 통합 테스트 |
| `bin` | `cases/<번호>/stdout` 은 모든 케이스에 필수. `args`, `stdin`, `stderr`, `code`, 픽스처 파일은 필요할 때만 |

금지 패턴을 정할 때는 두 가지를 확인한다.

- 과제가 요구하는 이름에 걸리지 않는지 본다. `split` 을 막으면서 `ft_split` 을 요구하면 모두가 KO 다.
- 과제 문서의 "금지" 칸과 같은지 본다. 학생은 문서만 본다.

마지막으로 참고 답안을 만들어 통과하는지 확인한다. 틀린 답안 몇 개가 KO 되는지도 확인한다. 실제 `rendu/` 를 더럽히지 않으려면 경로를 바꿔 돌린다.

```sh
PISCINE_RENDU=/tmp/answers PISCINE_WORK=/tmp/work ./grademe.sh module03
```

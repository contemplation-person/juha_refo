# Rust Piscine

42 의 피신(Piscine, "수영장") 방식으로 러스트를 익히는 과정이다.

강의는 없다. 과제(subject)만 있다. 과제를 읽고, 문서를 찾고, 직접 코드를 써서 채점기(moulinette)를 통과한다. 채점기는 사람처럼 봐주지 않는다. 출력 한 글자, 경고 하나도 틀리면 실패다.

---

## 빠른 시작

```sh
cd rust-piscine
cat subjects/module00.md          # 1. 과제를 읽는다

cd rendu && mkdir -p module00 && cd module00
cargo new --vcs none ex00         # 2. 과제마다 크레이트를 하나 만든다
# ... src/main.rs 작성 ...

cd ../..
./grademe.sh module00             # 3. 채점한다
./grademe.sh module00 ex03        #    과제 하나만 볼 수도 있다
cat rendu/deepthought             # 4. 실패했으면 이유를 읽는다
```

---

## 폴더 구조

```
rust-piscine/
├── README.md          이 문서
├── MOULINETTE.md      채점 규칙 전체
├── grademe.sh         채점기
├── subjects/          과제 설명 (module00.md ~ module09.md)
├── rendu/             내가 제출하는 곳 ("rendu" = 프랑스어로 "제출물")
│   └── module00/
│       ├── ex00/      cargo 크레이트 하나 = 과제 하나
│       └── ex01/
└── moulinette/        채점용 숨은 테스트 — 열어 보지 않는다
```

`moulinette/` 안에는 정답 판정용 테스트가 들어 있다. 열면 과제가 쉬워지는 대신 배우는 것이 사라진다. 막히면 테스트 대신 `rendu/deepthought` 의 실패 기록을 읽는다.

---

## 규칙

채점기는 아래를 순서대로 검사한다. 하나라도 걸리면 그 과제는 KO 다. 세부 기준, 과제별 금지 항목, 시간 제한은 [MOULINETTE.md](MOULINETTE.md) 에 있다.

| 순서 | 검사 | 실패 예 |
|------|------|---------|
| 1 | 제출물 위치와 패키지 이름 | `rendu/module00/ex01/Cargo.toml` 의 `name` 이 `ex01` 이 아님 |
| 2 | 외부 크레이트 | `[dependencies]` 에 무언가 적혀 있음 |
| 3 | `unsafe` 와 과제별 금지 항목 | 금지된 `.len(` 을 씀 |
| 4 | norm (코드 규칙) | `cargo fmt --check` 또는 `cargo clippy -- -D warnings` 실패 |
| 5 | 숨은 테스트 | 결과가 다름, 10초 초과, panic |

**첫 실패에서 멈춘다.** ex02 가 KO 면 ex03 부터는 검사하지 않는다. 42 의 채점 방식 그대로다. 앞 과제를 대충 넘기면 뒤 과제를 아무리 잘해도 점수가 없다.

**금지 항목 검사는 주석까지 본다.** 글자 검색이기 때문이다. 금지된 이름은 주석에도 쓰지 않는다.

**norm 은 러스트 공식 도구다.** 제출 전에 크레이트 폴더에서 두 줄을 돌린다.

```sh
cargo fmt                         # 모양을 자동으로 맞춘다
cargo clippy -- -D warnings       # 경고가 하나라도 있으면 실패
```

clippy 는 "돌아가지만 더 러스트다운 방법이 있다"를 알려주는 도구다. 경고 메시지에 고치는 법이 같이 나온다. 그 메시지를 읽는 것 자체가 공부다.

**`cargo new` 에는 `--vcs none` 을 붙인다.** 붙이지 않으면 과제마다 git 저장소가 따로 생긴다.

---

## 과정

| 모듈 | 주제 | 과제 | The Rust Book |
|------|------|------|---------------|
| [module00](subjects/module00.md) | 첫걸음: 변수, 함수, 조건, 반복 | 8 | 1, 3장 |
| [module01](subjects/module01.md) | 소유권과 빌림 | 6 | 4장 |
| [module02](subjects/module02.md) | 구조체, 열거형, match | 7 | 5, 6장 |
| [module03](subjects/module03.md) | 컬렉션: Vec, String, HashMap | 7 | 8장 |
| [module04](subjects/module04.md) | 에러 처리: Result, `?` | 7 | 9장 |
| [module05](subjects/module05.md) | 제네릭과 트레이트 | 7 | 10.1–10.2장 |
| [module06](subjects/module06.md) | 클로저와 반복자 | 7 | 13장 |
| [module07](subjects/module07.md) | 수명과 스마트 포인터 | 7 | 10.3, 15장 |
| [module08](subjects/module08.md) | 동시성: 스레드, 채널, Mutex | 5 | 16장 |
| [module09](subjects/module09.md) | 최종 과제: BSQ | 1 | 전부 |

책은 `rustup doc --book` 으로 오프라인에서 열린다. 온라인은 https://doc.rust-lang.org/book/ 이다. 표준 라이브러리 문서는 `rustup doc --std` 다.

---

## 피신답게 공부하는 법

- **과제를 끝까지 읽는다.** 함정과 힌트는 대개 마지막 문단에 있다.
- **컴파일러 에러를 읽는다.** 러스트 컴파일러는 고칠 곳과 고치는 법을 같이 알려준다. `rustc --explain E0382` 처럼 에러 번호로 긴 설명도 볼 수 있다.
- **답을 베끼지 않는다.** 검색과 질문은 자유다. 하지만 코드를 직접 치지 않으면 손에 남지 않는다. AI 에게 물을 때도 "답"이 아니라 "개념"을 묻는다.
- **테스트를 직접 짠다.** 숨은 테스트를 상상해서 `#[cfg(test)]` 로 먼저 시험한다. 경계값(0, 음수, 빈 문자열, 최댓값)이 단골 함정이다.

---

## 채점 기록 읽기

`./grademe.sh` 를 돌릴 때마다 `rendu/deepthought` 가 새로 쓰인다. 과제별로 아래가 남는다.

- 금지 항목에 걸린 줄
- `cargo fmt` 가 바꾸려는 부분 (diff)
- 컴파일 에러와 clippy 경고
- 실패한 테스트 이름과 panic 메시지
- 실행 파일 과제는 기대 출력과 실제 출력의 차이 (`<` 기대, `>` 실제)

채점기는 제출한 코드를 건드리지 않는다. `.work/` 에 사본을 만들어 검사한다. `.work/` 는 지워도 된다. 다음 채점 때 다시 생긴다.

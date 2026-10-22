# Module 00 — 첫걸음

> 변수, 함수, 조건문, 반복문. 러스트로 "생각대로 도는 코드"를 처음 써 본다.

읽을거리: The Rust Book 1장, 3장 (`rustup doc --book` 으로 오프라인에서도 열린다)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module00/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.

---

## ex00 : hello

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex00/` |
| 종류 | 실행 파일 — `cargo new --vcs none ex00` |
| 제출 파일 | `Cargo.toml`, `src/main.rs` |
| 금지 | 없음 |

`Hello, World!` 와 줄바꿈을 출력하는 프로그램을 만든다.

```
$ cargo run -q
Hello, World!
$
```

`cargo new` 가 만들어 주는 코드를 그대로 내도 통과할 수 있다. 그래도 `main` 이 무엇인지, `println!` 끝의 `!` 가 무슨 뜻인지는 알고 넘어간다.

---

## ex01 : max_of_three

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex01/` |
| 종류 | 라이브러리 — `cargo new --vcs none --lib ex01` |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `max(` 호출, `cmp::` |

세 정수 중 가장 큰 값을 돌려주는 함수를 만든다.

```rust
pub fn max_of_three(a: i32, b: i32, c: i32) -> i32
```

```rust
max_of_three(3, 9, 2)    // 9
max_of_three(-7, -3, -5) // -3
```

러스트에서 `if` 는 값을 만드는 식(expression)이다. `let x = if ... { ... } else { ... };` 처럼 쓸 수 있다.

---

## ex02 : fizzbuzz

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn fizzbuzz(n: u32) -> String
```

| n 의 조건 | 돌려줄 값 |
|-----------|-----------|
| 3 과 5 의 배수 | `"FizzBuzz"` |
| 3 의 배수 | `"Fizz"` |
| 5 의 배수 | `"Buzz"` |
| 그 외 | 숫자를 글자로 (`"7"`) |

0 은 3 과 5 의 배수다. 따라서 `fizzbuzz(0)` 은 `"FizzBuzz"` 다.

`match` 는 튜플도 비교할 수 있다. `match (n % 3, n % 5)` 를 떠올려 본다.

---

## ex03 : collatz_steps

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn collatz_steps(n: u64) -> u32
```

n 이 1 이 될 때까지 아래 규칙을 몇 번 적용하는지 센다.

- 짝수면 2 로 나눈다.
- 홀수면 3 을 곱하고 1 을 더한다.

`collatz_steps(1)` 은 0 이다. `collatz_steps(0)` 도 0 으로 정한다.

```
6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1   (8번)
```

중간값은 시작값보다 훨씬 커진다. 매개변수 `n` 을 바꾸려면 `mut` 이 필요하다.

---

## ex04 : is_prime

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn is_prime(n: u64) -> bool
```

n 이 소수면 `true` 를 돌려준다. 0 과 1 은 소수가 아니다.

채점에는 1조에 가까운 수도 나온다. 1 부터 n 까지 전부 나눠 보면 시간 제한(10초)에 걸린다. 약수는 짝을 이룬다는 점을 생각한다. `n = 36` 이면 `(2, 18)`, `(3, 12)`, `(6, 6)` 이다.

`i * i <= n` 은 n 이 아주 크면 넘칠(overflow) 수 있다. 넘치지 않는 다른 비교 방법을 찾는다.

---

## ex05 : print_comb

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex05/` |
| 종류 | 실행 파일 |
| 제출 파일 | `Cargo.toml`, `src/main.rs` |
| 금지 | 없음 |

서로 다른 숫자 세 개를 오름차순으로 고른 모든 조합을 출력한다. 조합 사이는 `", "` 로 나누고 맨 끝에 줄바꿈 하나를 둔다.

```
$ cargo run -q
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, ..., 679, 689, 789
$
```

`...` 은 지면을 줄인 것이다. 실제로는 120개를 모두 출력한다. `789` 뒤에는 쉼표가 없다.

---

## ex06 : print_params

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex06/` |
| 종류 | 실행 파일 |
| 제출 파일 | `Cargo.toml`, `src/main.rs` |
| 금지 | 없음 |

받은 인자를 한 줄에 하나씩, 받은 순서대로 출력한다. 프로그램 이름은 빼고 출력한다.

```
$ cargo run -q -- hello "Rust Piscine" 한글
hello
Rust Piscine
한글
$ cargo run -q
$
```

`cargo run` 뒤의 `--` 는 "여기부터는 cargo 가 아니라 내 프로그램 인자"라는 뜻이다. 인자는 `std::env::args()` 로 받는다.

---

## ex07 : fibonacci

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module00/ex07/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn fibonacci(n: u32) -> u64
```

피보나치 수열의 n 번째 값을 돌려준다. `fibonacci(0) = 0`, `fibonacci(1) = 1` 이다. 그 뒤는 앞의 두 값을 더한다.

n 은 0 이상 93 이하만 들어온다. `fibonacci(93)` 은 u64 에 담기는 가장 큰 피보나치 수다.

함정이 둘 있다.

- 자기 자신을 두 번 부르는 재귀는 `fibonacci(50)` 에서 시간 제한에 걸린다.
- 필요 없는 다음 항까지 미리 더하면 `fibonacci(93)` 에서 넘친다. 디버그 빌드의 러스트는 정수가 넘치면 조용히 틀리지 않고 panic 으로 멈춘다.

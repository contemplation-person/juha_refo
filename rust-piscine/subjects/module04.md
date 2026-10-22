# Module 04 — 에러 처리

> `Result`, `?`, 직접 만든 에러 타입. 실패도 값으로 다룬다.

읽을거리: The Rust Book 9장 (`rustup doc --book`)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module04/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.

러스트에는 예외(exception)가 없다. 실패할 수 있는 함수는 `Result<성공값, 에러값>` 을 돌려준다. 받는 쪽은 둘 중 무엇인지 확인하기 전에는 성공값을 꺼낼 수 없다. 그래서 에러를 깜빡 잊고 지나가는 일이 컴파일 단계에서 막힌다.

---

## ex00 : parse_age

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex00/` |
| 종류 | 라이브러리 — `cargo new --vcs none --lib ex00` |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

문자열을 나이로 읽는다.

```rust
pub fn parse_age(s: &str) -> Result<u8, String>
```

아래 순서로 검사한다.

| 순서 | 조건 | 돌려줄 값 |
|------|------|-----------|
| 1 | 앞뒤 공백을 지운(`trim`) 결과가 빈 문자열 | `Err("empty")` |
| 2 | 그 결과를 `u32` 로 `parse` 하지 못함 | `Err("not a number")` |
| 3 | 150 보다 큼 | `Err("too old")` |
| 4 | 그 외 | `Ok(나이)` |

```rust
parse_age(" 7 \n")  // Ok(7)
parse_age("-5")     // Err("not a number")
parse_age("200")    // Err("too old")
```

`str::parse` 는 `Result` 를 돌려준다. 실패했을 때의 에러를 내 에러로 바꾸려면 `map_err` 를 쓴다.

`u8` 로 바로 읽지 않는 이유가 있다. `"200"` 은 `u8` 범위(0~255) 안이지만 `"300"` 은 아니다. `u8` 로 읽으면 `"300"` 이 "too old" 가 아니라 "not a number" 가 된다.

---

## ex01 : check_password

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

에러를 문자열 대신 열거형으로 만든다.

```rust
#[derive(Debug, PartialEq)]
pub enum PasswordError {
    TooShort,
    NoDigit,
    NoUppercase,
}

pub fn check_password(pw: &str) -> Result<(), PasswordError>
```

아래 순서로 검사한다. 처음 걸린 에러 하나만 돌려준다.

| 순서 | 조건 | 에러 | 화면 표시 (`Display`) |
|------|------|------|------------------------|
| 1 | 글자 수가 8 미만 | `TooShort` | `password must be at least 8 characters` |
| 2 | ASCII 숫자가 없음 | `NoDigit` | `password must contain a digit` |
| 3 | ASCII 대문자가 없음 | `NoUppercase` | `password must contain an uppercase letter` |

- 글자 수는 바이트 수가 아니다. `"A1한글"` 은 4글자다.
- `É` 는 대문자지만 ASCII 가 아니므로 세지 않는다.

`PasswordError` 에 `std::fmt::Display` 와 `std::error::Error` 를 구현한다. `Error` 는 `Debug` 와 `Display` 만 있으면 몸통 없이 `impl std::error::Error for PasswordError {}` 로 충분하다.

```rust
check_password("Longpassword1")  // Ok(())
check_password("longpassword")   // Err(PasswordError::NoDigit)
PasswordError::NoDigit.to_string() // "password must contain a digit"
```

`Error` 를 구현하면 `Box<dyn std::error::Error>` 에 담을 수 있다. 서로 다른 에러 타입을 한 그릇에 모을 때 쓰는 표준 방법이다.

---

## ex02 : sum_csv

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `match`, `.unwrap...`, `.expect(` |

쉼표로 나눈 정수들을 더한다.

```rust
use std::num::ParseIntError;

pub fn sum_csv(s: &str) -> Result<i64, ParseIntError>
```

- `,` 로 나눈 조각마다 앞뒤 공백을 지우고 `i64` 로 읽는다.
- 하나라도 읽지 못하면 그 조각의 `ParseIntError` 를 그대로 돌려준다. 앞에서부터 처음 실패한 조각이다.
- 빈 조각도 에러다. `""`, `"1,,2"`, `"1,2,"` 는 모두 실패한다.
- 합이 i64 를 넘는 입력은 들어오지 않는다.

```rust
sum_csv(" 10 , -4 ,5 ")  // Ok(11)
sum_csv("1,x,3")         // Err(..)  kind() == InvalidDigit
sum_csv("1,,2")          // Err(..)  kind() == Empty
```

이 과제의 목표는 `?` 다. `값?` 은 "`Ok` 면 안의 값을 꺼내고, `Err` 면 이 함수에서 그 에러를 곧장 돌려줘라"는 뜻이다. `match` 와 `unwrap` 을 막은 이유가 이것이다. 4줄이면 충분하다.

---

## ex03 : display_file

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex03/` |
| 종류 | 실행 파일 — `cargo new --vcs none ex03` |
| 제출 파일 | `Cargo.toml`, `src/main.rs` |
| 금지 | 없음 |

인자로 받은 파일 하나의 내용을 그대로 출력한다.

| 상황 | stdout | stderr | 종료 코드 |
|------|--------|--------|-----------|
| 인자 1개, 읽기 성공 | 파일 내용 그대로 | 없음 | 0 |
| 인자 없음 | 없음 | `File name missing.` + 줄바꿈 | 1 |
| 인자 2개 이상 | 없음 | `Too many arguments.` + 줄바꿈 | 1 |
| 읽기 실패 (없는 파일, 디렉터리 등) | 없음 | `Cannot read file.` + 줄바꿈 | 1 |

```
$ cargo run -q -- hello.txt
Hello, Piscine!
$ cargo run -q
File name missing.
$ echo $?
1
```

파일 끝에 줄바꿈이 없으면 출력에도 없어야 한다. `println!` 은 줄바꿈을 하나 더 붙인다. 에러 메시지는 `eprintln!` 으로 stderr 에 쓴다.

`std::process::exit(1)` 로 종료 코드를 정한다. `main` 이 그냥 끝나면 0 이다. 패닉으로 끝나면 101 이다.

`std::fs::read_to_string` 과 `std::fs::read` 모두 `Result` 를 돌려준다. 둘의 차이는 UTF-8 이 아닌 파일에서 드러난다.

---

## ex04 : ft_atoi

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.parse`, `from_str`, `i64`, `i128`, `u64`, `u128` |

문자열을 `i32` 로 직접 읽는다. 표준 라이브러리 `parse` 의 동작을 손으로 다시 만드는 과제다.

```rust
#[derive(Debug, PartialEq)]
pub enum AtoiError {
    Empty,
    InvalidDigit,
    Overflow,
}

pub fn ft_atoi(s: &str) -> Result<i32, AtoiError>
```

허용하는 모양은 하나다. 맨 앞에 `+` 또는 `-` 가 0개나 1개, 그 뒤에 ASCII 숫자가 1개 이상이다.

| 순서 | 조건 | 에러 | `Display` |
|------|------|------|-----------|
| 1 | 빈 문자열 | `Empty` | `empty string` |
| 2 | 위 모양이 아님 (공백, 부호만 있음, 부호 두 개, 숫자 아닌 글자) | `InvalidDigit` | `invalid digit found` |
| 3 | 모양은 맞지만 i32 범위 밖 | `Overflow` | `number out of range for i32` |

글자 검사를 먼저 끝낸다. `"99999999999999999999a"` 는 `Overflow` 가 아니라 `InvalidDigit` 이다.

```rust
ft_atoi("+42")          // Ok(42)
ft_atoi("-2147483648")  // Ok(i32::MIN)
ft_atoi("2147483648")   // Err(AtoiError::Overflow)
ft_atoi(" 42")          // Err(AtoiError::InvalidDigit)
ft_atoi("-")            // Err(AtoiError::InvalidDigit)
```

`AtoiError` 에 `Display` 와 `std::error::Error` 를 구현한다.

더 큰 정수 타입이 막혀 있다. 넘침은 `checked_mul`, `checked_add`, `checked_sub` 로 잡는다. 이 메서드들은 넘치면 `None` 을 준다. `Option` 은 `ok_or(에러)` 로 `Result` 가 되고, 그다음은 `?` 로 이어진다.

i32 는 양수 쪽이 하나 짧다. `2147483648` 은 담을 수 없지만 `-2147483648` 은 담을 수 있다. 양수로 다 읽은 뒤 부호를 붙이면 `i32::MIN` 에서 넘친다. 음수면 처음부터 빼 나가는 방법을 생각한다.

---

## ex05 : eval_rpn

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

역폴란드 표기(RPN) 수식을 계산한다. RPN 은 연산자를 피연산자 뒤에 쓴다. `3 4 +` 는 `3 + 4`, `5 1 2 + 4 * + 3 -` 는 `5 + (1 + 2) * 4 - 3` 이다. 괄호가 필요 없다.

```rust
#[derive(Debug, PartialEq)]
pub enum CalcError {
    Empty,
    InvalidToken(String),
    NotEnoughOperands,
    DivisionByZero,
    Overflow,
    TooManyOperands,
}

pub fn eval_rpn(expr: &str) -> Result<i64, CalcError>
```

계산 방법은 다음과 같다.

1. 공백 문자로 나눈 토큰을 왼쪽부터 하나씩 본다.
2. 숫자면 스택(`Vec`)에 넣는다.
3. 연산자(`+ - * /`)면 두 개를 꺼내 계산하고 결과를 넣는다. 먼저 꺼낸 것이 오른쪽 값이다.
4. 끝나면 스택에 정확히 하나가 남아야 한다.

나눗셈은 러스트 `/` 처럼 0 쪽으로 버린다 (`-7 2 /` → `-3`). 토큰이 정확히 `-` 하나면 연산자이고, `-3` 이면 숫자다.

| 상황 | 에러 | `Display` |
|------|------|-----------|
| 토큰이 하나도 없음 | `Empty` | `empty expression` |
| 연산자도 아니고 i64 로 읽히지도 않는 토큰 | `InvalidToken(토큰)` | `invalid token: <토큰>` |
| 연산자를 만났는데 스택에 2개 미만 | `NotEnoughOperands` | `not enough operands` |
| 0 으로 나눔 | `DivisionByZero` | `division by zero` |
| 계산 결과가 i64 를 넘음 | `Overflow` | `overflow` |
| 끝났는데 스택에 2개 이상 | `TooManyOperands` | `too many operands` |

에러는 왼쪽부터 처음 만난 것 하나만 돌려준다. `1 0 / x` 는 `DivisionByZero` 다.

```rust
eval_rpn("10 3 -")           // Ok(7)
eval_rpn("1 2")              // Err(CalcError::TooManyOperands)
eval_rpn("1 2 x +")          // Err(CalcError::InvalidToken("x".to_string()))
eval_rpn("-9223372036854775808 -1 /")  // Err(CalcError::Overflow)
```

`CalcError` 에 `Display` 와 `std::error::Error` 를 구현한다.

마지막 예시는 0 으로 나누지 않았는데도 넘친다. `i64::MIN / -1` 의 답은 `i64::MAX + 1` 이기 때문이다. `checked_div` 가 이 경우도 `None` 으로 알려 준다.

`Vec::pop` 은 `Option` 을 돌려준다. 스택이 비었는지 따로 확인할 필요 없이 `pop().ok_or(...)?` 한 줄로 처리된다.

---

## ex06 : parse_config

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module04/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `map_err`, `.unwrap...`, `.expect(` |

`key=value` 줄로 된 설정 글을 읽는다. 에러 하나가 다른 에러를 품는 구조를 만든다.

```rust
use std::num::ParseIntError;

#[derive(Debug, PartialEq)]
pub struct Config {
    pub width: u32,
    pub height: u32,
}

#[derive(Debug, PartialEq)]
pub enum ConfigError {
    BadLine(usize),
    UnknownKey(String),
    BadNumber(ParseIntError),
    MissingKey(String),
}

pub fn parse_config(text: &str) -> Result<Config, ConfigError>
```

줄 단위로 읽는다. 줄 번호는 1 부터 센다.

1. 앞뒤 공백을 지운다. 빈 줄과 `#` 으로 시작하는 줄은 건너뛴다.
2. `=` 가 없으면 `BadLine(줄 번호)` 다.
3. 첫 `=` 앞이 키, 뒤가 값이다. 둘 다 앞뒤 공백을 지운다.
4. 키가 `width`, `height` 가 아니면 `UnknownKey(키)` 다.
5. 값을 `u32` 로 읽지 못하면 `BadNumber(그 ParseIntError)` 다.
6. 같은 키가 여러 번 나오면 마지막 값이 이긴다.
7. 다 읽은 뒤 `width` 가 없으면 `MissingKey("width")`, 그다음 `height` 가 없으면 `MissingKey("height")` 다.

| 에러 | `Display` |
|------|-----------|
| `BadLine(3)` | `line 3: expected key=value` |
| `UnknownKey("color")` | `unknown key: color` |
| `BadNumber(e)` | `bad number: ` 뒤에 `e` 의 `Display` |
| `MissingKey("height")` | `missing key: height` |

함께 구현할 것이 둘이다.

- `impl From<ParseIntError> for ConfigError` — `ParseIntError` 를 `BadNumber` 로 감싼다.
- `impl std::error::Error for ConfigError` — `source()` 가 `BadNumber` 면 안의 `ParseIntError` 를, 나머지는 `None` 을 돌려준다.

```rust
parse_config("# size\nwidth = 80\nheight=24")  // Ok(Config { width: 80, height: 24 })
parse_config("width=80\nheight")               // Err(ConfigError::BadLine(2))
parse_config("width=abc")                      // Err(ConfigError::BadNumber(..))
```

`?` 는 에러를 돌려주기 전에 `From::from` 을 부른다. `From<ParseIntError>` 를 구현해 두면 `value.parse::<u32>()?` 가 `ParseIntError` 를 `ConfigError` 로 알아서 바꾼다. `map_err` 를 막은 이유가 이것이다.

`source()` 는 "이 에러의 원인이 된 에러"다. 로그를 찍는 쪽은 `source()` 를 따라가며 원인 사슬 전체를 보여 줄 수 있다.

`text.lines().enumerate()` 는 0 부터 센다. 줄 번호는 1 을 더한다. `str::split_once('=')` 는 `Option<(&str, &str)>` 을 준다.

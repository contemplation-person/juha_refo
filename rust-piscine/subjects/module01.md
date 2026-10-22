# Module 01 — 소유권과 빌림

> 값에는 주인이 하나뿐이다. 남의 값은 빌려서(`&`) 보거나, 허락받고(`&mut`) 고친다.

읽을거리: The Rust Book 4장 (소유권, 참조와 빌림, 슬라이스)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module01/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.

이 모듈의 과제는 모두 라이브러리다. `cargo new --vcs none --lib exNN` 으로 만든다.

---

## ex00 : ft_div_mod

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn ft_div_mod(a: i32, b: i32, div: &mut i32, rem: &mut i32)
```

`a / b` 의 몫을 `div` 에, 나머지를 `rem` 에 써 넣는다. 함수는 아무것도 돌려주지 않는다. b 는 0 이 아니다.

```rust
let mut div = 0;
let mut rem = 0;
ft_div_mod(7, 2, &mut div, &mut rem);
// div == 3, rem == 1
```

`&mut i32` 는 "남의 i32 를 고쳐도 된다는 허가증"이다. 허가증 자체가 아니라 그것이 가리키는 값을 바꾸려면 `*` 를 붙인다.

러스트의 정수 나눗셈은 0 쪽으로 버린다. `-7 / 2` 는 `-3`, `-7 % 2` 는 `-1` 이다.

---

## ex01 : ft_strlen

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.len(`, `.count(` |

```rust
pub fn ft_strlen(s: &str) -> usize
```

문자열의 글자 수를 돌려준다. 바이트 수가 아니다.

```rust
ft_strlen("hello") // 5
ft_strlen("한글")  // 2
ft_strlen("🦀")    // 1
```

러스트 문자열은 UTF-8 이다. `"한글".len()` 은 6 이다. 한글 한 글자가 3 바이트이기 때문이다. 글자 단위로 보려면 `.chars()` 를 쓴다.

매개변수가 `String` 이 아니라 `&str` 인 이유도 생각한다. `&str` 로 받으면 `"리터럴"` 도, `&my_string` 도 넘길 수 있다. 그리고 함수는 값을 빌려만 가므로 호출한 쪽은 문자열을 계속 쓸 수 있다.

---

## ex02 : first_word

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `split` 계열(`.split(`, `.split_whitespace(` 등), `.find(`, `.rfind(`, `trim`, `.position(` |

```rust
pub fn first_word(s: &str) -> &str
```

첫 공백 문자(`' '`) 앞까지를 돌려준다. 공백이 없으면 문자열 전체를 돌려준다.

```rust
first_word("hello world") // "hello"
first_word("hello")       // "hello"
first_word(" hello")      // ""
first_word("한글 단어")   // "한글"
```

새 `String` 을 만들지 않는다. 원래 문자열의 일부를 가리키는 슬라이스(`&s[a..b]`)를 돌려준다. 채점은 돌려준 값이 원래 문자열 안을 가리키는지도 확인한다.

슬라이스 범위는 바이트 위치다. 공백은 1 바이트 ASCII 문자이므로 `.bytes()` 나 `.as_bytes()` 로 찾은 위치에서 잘라도 글자가 깨지지 않는다.

Rust Book 의 예제 코드를 그대로 내면 clippy 에 걸린다. 마지막 줄 `&s[..]` 는 `s` 와 같다(`redundant_slicing`). clippy 의 제안을 읽고 왜 같은지 이해한 뒤 고친다.

---

## ex03 : ft_strrev

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `rev(` |

```rust
pub fn ft_strrev(s: &mut String)
```

받은 문자열을 글자 단위로 뒤집는다. 돌려주지 않고 그 자리에서 바꾼다.

```rust
let mut s = String::from("한글abc");
ft_strrev(&mut s);
// s == "cba글한"
```

바이트 단위로 뒤집으면 한글이 깨진다. 글자 단위로 뒤집는다.

`&mut String` 은 문자열 전체를 바꿀 권한이다. 새 문자열을 만든 뒤 `*s = 새문자열;` 로 통째로 바꿔 끼워도 된다. 그때 옛 문자열은 주인이 없어져 자동으로 해제된다.

---

## ex04 : ft_strcapitalize

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn ft_strcapitalize(s: &str) -> String
```

각 단어의 첫 글자를 대문자로, 나머지를 소문자로 바꾼 새 문자열을 돌려준다.

단어는 ASCII 영문자와 숫자가 이어진 덩어리다. 그 밖의 글자(공백, 기호, 한글 등)는 모두 단어를 나누는 구분자이며 그대로 둔다.

```rust
ft_strcapitalize("salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un")
// "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"

ft_strcapitalize("HELLO wORLD") // "Hello World"
ft_strcapitalize("한글abc")     // "한글Abc"
```

`42mots` 는 숫자로 시작하는 한 단어다. 첫 글자 `4` 는 대문자가 없으니 그대로이고, 뒤의 `mots` 는 소문자가 된다.

입력은 빌려 받고(`&str`), 결과는 새로 만들어 넘긴다(`String`). 돌려준 `String` 의 주인은 이제 호출한 쪽이다.

`char` 에는 `is_ascii_alphanumeric`, `to_ascii_uppercase`, `to_ascii_lowercase` 가 있다. "지금 단어 안에 있는가"를 기억하는 변수 하나면 충분하다.

---

## ex05 : ft_strjoin

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module01/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.join(`, `concat` |

```rust
pub fn ft_strjoin(strs: &[&str], sep: &str) -> String
```

문자열 조각들 사이에 `sep` 를 끼워 하나로 이은 새 문자열을 돌려준다.

```rust
ft_strjoin(&["a", "b", "c"], ", ") // "a, b, c"
ft_strjoin(&["only"], " -- ")      // "only"
ft_strjoin(&[], ", ")              // ""
ft_strjoin(&["", ""], "-")         // "-"
```

`&[&str]` 는 "빌린 문자열들을 담은 배열을, 다시 빌린 것"이다. 함수는 아무것도 가져가지 않는다. 새로 만드는 것은 돌려줄 `String` 하나뿐이다.

구분자는 조각과 조각 사이에만 들어간다. 맨 앞이나 맨 뒤에 붙지 않게 한다.

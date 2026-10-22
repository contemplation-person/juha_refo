# Module 03 — 컬렉션

> `Vec`, `String`, `HashMap`. 값을 여러 개 담고, 늘리고, 찾는다.

읽을거리: The Rust Book 8장 (`rustup doc --book`)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module03/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.

---

## ex00 : ft_range

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex00/` |
| 종류 | 라이브러리 — `cargo new --vcs none --lib ex00` |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.collect`, `.to_vec`, `extend`, `vec![값; 개수]` 처럼 내용을 채운 `vec!` |

`min` 이상 `max` 미만의 정수를 차례로 담은 `Vec` 을 돌려준다. `min >= max` 면 빈 `Vec` 이다.

```rust
pub fn ft_range(min: i32, max: i32) -> Vec<i32>
```

```rust
ft_range(-3, 2)  // [-3, -2, -1, 0, 1]
ft_range(4, 4)   // []
ft_range(10, -10) // []
```

빈 `Vec` 을 만들고 `push` 로 하나씩 넣는다. `Vec` 은 꽉 차면 더 큰 자리로 이사한다. 개수를 미리 알면 `Vec::with_capacity` 로 처음부터 넉넉히 잡아 이사를 줄일 수 있다.

개수를 `max - min` 으로 구할 때 조심한다. `ft_range(i32::MAX, i32::MIN)` 에서 이 뺄셈은 i32 범위를 넘는다. 디버그 빌드는 이때 panic 으로 멈춘다.

---

## ex01 : ft_sort_int_tab

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.sort` 로 시작하는 모든 메서드, `BinaryHeap`, `BTree` |

정수 슬라이스를 오름차순으로 제자리 정렬한다. 새 `Vec` 을 만들어 돌려주지 않는다.

```rust
pub fn ft_sort_int_tab(tab: &mut [i32])
```

```rust
let mut v = vec![5, 2, 9, 1, 3];
ft_sort_int_tab(&mut v);
// v == [1, 2, 3, 5, 9]
```

`&mut [i32]` 는 "남의 배열 한 구간을 고칠 권한"이다. `Vec` 전체든 배열 일부(`&mut arr[1..4]`)든 받을 수 있다. 원소 두 개를 맞바꿀 때는 `tab.swap(i, j)` 를 쓴다. `let t = tab[i]; tab[i] = tab[j]; tab[j] = t;` 도 된다.

거품 정렬이나 선택 정렬이면 충분하다. 채점에는 3000개짜리 배열도 나오지만 시간 제한 안에 끝난다.

---

## ex02 : ft_split

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.split...` 계열 메서드 전부, `str::split...`, `.lines(` |

`s` 를 `charset` 에 든 글자 중 아무것으로나 자른다. 빈 조각은 버린다.

```rust
pub fn ft_split(s: &str, charset: &str) -> Vec<String>
```

```rust
ft_split("  a  b ", " ")      // ["a", "b"]
ft_split("a,b;;c", ",;")      // ["a", "b", "c"]
ft_split("사과,배;포도", ",;") // ["사과", "배", "포도"]
ft_split("abc", "")           // ["abc"]
ft_split(",,,", ",")          // []
```

글자 단위로 돌려면 `s.chars()` 를 쓴다. `s.bytes()` 로 돌면 한글이 세 조각으로 부서진다. 지금 만드는 단어는 `String` 하나에 모은다. 구분자를 만나면 그 `String` 을 결과 `Vec` 으로 옮긴다.

`words.push(current)` 를 하면 `current` 의 소유권이 `Vec` 으로 넘어간다. 그 뒤 `current` 를 다시 쓰려면 `current = String::new();` 로 새 값을 줘야 한다. 컴파일러가 이 부분을 짚어 줄 것이다.

---

## ex03 : word_count

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

글에 나온 단어마다 몇 번 나왔는지 센다.

```rust
use std::collections::HashMap;

pub fn word_count(text: &str) -> HashMap<String, usize>
```

- 단어는 `char::is_alphanumeric` 이 참인 글자가 이어진 덩어리다. 나머지 글자는 모두 구분자다.
- 키는 소문자로 바꿔 넣는다 (`str::to_lowercase`).

```rust
word_count("Hello, hello! HELLO world.")  // {"hello": 3, "world": 1}
word_count("don't")                        // {"don": 1, "t": 1}
word_count("러스트, 러스트! ÉCOLE école")  // {"러스트": 2, "école": 2}
```

`HashMap` 에 "없으면 0 으로 넣고, 있으면 1 더하기"는 `entry` API 한 줄로 끝난다. `*map.entry(key).or_insert(0) += 1;` 을 풀어서 읽어 본다. `entry` 는 칸을 찾고, `or_insert` 는 그 칸의 `&mut` 을 돌려준다.

---

## ex04 : median, mode

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn median(v: &[i32]) -> Option<f64>
pub fn mode(v: &[i32]) -> Option<i32>
```

| 함수 | 돌려줄 값 |
|------|-----------|
| `median` | 정렬했을 때 가운데 값. 개수가 짝수면 가운데 두 값의 평균 |
| `mode` | 가장 많이 나온 값. 같은 횟수면 더 작은 값 |
| 둘 다 | 빈 슬라이스면 `None` |

```rust
median(&[3, 1, 2])     // Some(2.0)
median(&[4, 1, 3, 2])  // Some(2.5)
mode(&[1, 2, 2, 3])    // Some(2)
mode(&[3, 1, 3, 1])    // Some(1)
```

`v` 는 빌려 온 값이라 정렬할 수 없다. 정렬하려면 `v.to_vec()` 으로 내 것을 하나 만든다.

평균을 낼 때 두 i32 를 먼저 더하면 `i32::MAX + i32::MAX` 에서 넘친다. f64 로 바꾼 뒤 더한다.

`x % 2 == 0` 을 쓰면 clippy 가 `x.is_multiple_of(2)` 로 바꾸라고 막는다. 뜻이 더 분명한 이름을 쓰라는 요구다.

---

## ex05 : ft_convert_base

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `from_str_radix` |

`base_from` 진법으로 쓴 `nbr` 를 읽어 `base_to` 진법 문자열로 바꾼다.

```rust
pub fn ft_convert_base(nbr: &str, base_from: &str, base_to: &str) -> Option<String>
```

진법은 "숫자로 쓸 글자 목록"이다. `"0123456789"` 는 10진법, `"01"` 은 2진법, `"poneyvif"` 는 `p=0, o=1, ..., f=7` 인 8진법이다. 한글도 글자다.

진법이 아래 중 하나라도 해당하면 `None` 이다. `base_from`, `base_to` 둘 다 검사한다.

- 글자가 2개 미만이다.
- 같은 글자가 두 번 나온다.
- `+`, `-`, 공백 문자(`char::is_whitespace`)가 들어 있다.

`nbr` 은 다음 순서로 읽는다.

1. 앞쪽 공백 문자를 건너뛴다.
2. `+`, `-` 를 개수 제한 없이 읽는다. `-` 가 홀수 개면 음수다.
3. 진법에 있는 글자를 읽는다. 진법에 없는 글자를 만나면 거기서 멈춘다.

결과 규칙은 다음과 같다.

- 숫자가 하나도 없으면 0 이다.
- 0 은 부호 없이 `base_to` 의 첫 글자 하나다.
- 음수면 앞에 `-` 를 붙인다.
- 절댓값은 `i64::MAX` 를 넘지 않는 입력만 들어온다.

```rust
ft_convert_base("42", "0123456789", "01")                  // Some("101010")
ft_convert_base("  --+-2a", "0123456789abcdef", "0123456789") // Some("-42")
ft_convert_base("12abc34", "0123456789", "0123456789")     // Some("12")
ft_convert_base("5", "0123456789", "가나다")                // Some("나다")
ft_convert_base("1", "0120", "01")                          // None
```

글자 → 값을 빨리 찾으려면 `HashMap<char, i64>` 를 만든다. 값 → 글자는 `Vec<char>` 에 인덱스로 찾는다. 같은 정보를 두 방향으로 쓰니 그릇도 두 개다.

나머지 연산으로 자릿수를 뽑으면 끝자리부터 나온다. 모은 뒤 뒤집는다.

---

## ex06 : Company

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module03/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

부서별 직원 명단을 관리한다. 필드 구성은 자유다.

```rust
pub struct Company { /* 자유 */ }

impl Company {
    pub fn new() -> Company
    pub fn execute(&mut self, command: &str) -> bool
    pub fn department(&self, name: &str) -> Vec<String>
    pub fn all(&self) -> Vec<(String, Vec<String>)>
}
```

`Company::default()` 도 동작해야 한다. `new()` 와 같은 빈 회사다.

`execute` 는 `"Add <이름> to <부서>"` 명령 하나를 처리한다.

- 공백 문자로 나눈 단어가 정확히 4개여야 한다. 단어 사이 공백 개수는 상관없다.
- 첫 단어는 `Add`, 셋째 단어는 `to` 다. 대소문자를 구분한다.
- 같은 부서에 같은 이름이 이미 있으면 받지 않는다.
- 받으면 `true`, 받지 않으면 아무것도 바꾸지 않고 `false` 를 돌려준다.

| 함수 | 돌려줄 값 |
|------|-----------|
| `department` | 그 부서 직원 이름을 사전순으로. 없는 부서면 빈 `Vec` |
| `all` | `(부서, 직원 목록)` 을 부서 이름 사전순으로. 직원 목록도 사전순 |

```rust
let mut c = Company::new();
c.execute("Add Sally to Engineering"); // true
c.execute("Add Amir to Sales");        // true
c.execute("Add Bob to Engineering");   // true
c.execute("Add Bob to Engineering");   // false (중복)
c.execute("add Tom to Sales");         // false (소문자 add)
c.department("Engineering");           // ["Bob", "Sally"]
c.all();  // [("Engineering", ["Bob", "Sally"]), ("Sales", ["Amir"])]
```

`HashMap<String, Vec<String>>` 이 자연스럽다. `HashMap` 은 순서를 보장하지 않는다. 사전순 결과가 필요하면 꺼낸 뒤 정렬한다. 이 과제에는 `.sort` 금지가 없다.

인자 없는 `pub fn new()` 만 있으면 clippy 가 `Default` 도 구현하라고 막는다(`new_without_default`). 구조체에 `#[derive(Default)]` 를 붙이고 `new` 에서 `Company::default()` 를 부르면 둘 다 해결된다.

`let [a, b, c, d] = words[..] else { return false; };` 처럼 슬라이스 패턴으로 "정확히 4개"를 한 번에 확인할 수 있다.

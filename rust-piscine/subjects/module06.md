# Module 06 — 클로저와 반복자

> 함수를 값처럼 넘기고(클로저), 반복을 조립해서 쓰는(반복자) 법을 익힌다.

읽을거리: The Rust Book 13장 (`rustup doc --book`)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module06/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.
- 이 모듈은 모두 라이브러리다. `cargo new --vcs none --lib exNN` 으로 만든다.

클로저는 주변 변수를 붙잡아 둔 익명 함수다. 붙잡은 변수를 어떻게 쓰느냐에 따라 트레이트가 셋으로 나뉜다.

| 트레이트 | 붙잡은 변수를 | 몇 번 부를 수 있나 | 예 |
|----------|---------------|---------------------|----|
| `Fn` | 읽기만 한다 | 몇 번이든 | `\|x\| x + n` |
| `FnMut` | 바꾼다 | 몇 번이든, 단 `mut` 로 들고 있어야 한다 | `\|x\| v.push(x)` |
| `FnOnce` | 가져가 버린다 | 한 번 | `move \|\| drop(s)` |

받는 쪽에서는 가장 너그러운 것을 요구하는 게 좋다. `FnMut` 을 받으면 `Fn` 클로저도 넘길 수 있다. 거꾸로는 안 된다.

---

## ex00 : ft_foreach, ft_map

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.map(` `.for_each(` `.filter(` `.filter_map(` `.any(` `.all(` `.count(` `.fold(` `.position(` `.find(` `.collect(` `.sum(` `.extend(` |

반복자 어댑터 없이, 직접 반복문으로 만든다.

```rust
pub fn ft_foreach<T, F: FnMut(&T)>(tab: &[T], f: F)
pub fn ft_map<T, U, F: FnMut(&T) -> U>(tab: &[T], f: F) -> Vec<U>
```

- `ft_foreach` 는 원소마다 앞에서부터 `f` 를 부른다.
- `ft_map` 은 원소마다 `f` 를 부른 결과를 같은 순서로 모은다. 결과 타입 `U` 는 `T` 와 달라도 된다.

```rust
let mut sum = 0;
ft_foreach(&[1, 2, 3], |x| sum += x);   // sum == 6
ft_map(&[1, 2, 3], |x| x.to_string())  // ["1", "2", "3"]
```

`f` 를 부르려면 `f` 자체가 바뀔 수 있어야 한다. `FnMut` 클로저는 부를 때마다 안에 붙잡은 상태를 바꾸기 때문이다. 매개변수를 `mut f: F` 로 받는다.

금지 목록은 주석까지 검사한다. 주석에 `.map(` 같은 글자를 쓰지 않는다.

---

## ex01 : ft_any, ft_count_if, ft_is_sort

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | ex00 목록에서 `.extend(` 를 뺀 것, 그리고 `.is_sorted` 로 시작하는 모든 메서드 |

```rust
use std::cmp::Ordering;

pub fn ft_any<T, F: FnMut(&T) -> bool>(tab: &[T], f: F) -> bool
pub fn ft_count_if<T, F: FnMut(&T) -> bool>(tab: &[T], f: F) -> usize
pub fn ft_is_sort<T, F: FnMut(&T, &T) -> Ordering>(tab: &[T], f: F) -> bool
```

| 함수 | 돌려줄 값 |
|------|-----------|
| `ft_any` | `f` 가 `true` 인 원소가 하나라도 있으면 `true`. 찾는 즉시 멈춘다 |
| `ft_count_if` | `f` 가 `true` 인 원소의 개수 |
| `ft_is_sort` | `f` 기준으로 오름차순이거나 내림차순이면 `true` |

`ft_is_sort` 의 `f(a, b)` 는 a 가 b 보다 작으면 `Less`, 같으면 `Equal`, 크면 `Greater` 다. 같은 값이 이어지는 것은 정렬을 깨지 않는다. 원소가 0개나 1개면 `true` 다.

```rust
ft_any(&[1, 3, 4], |x| x % 2 == 0)              // true
ft_count_if(&["", "a", ""], |s| s.is_empty())   // 2
ft_is_sort(&[9, 4, 4, 0], |a, b| a.cmp(b))      // true (내림차순)
ft_is_sort(&["a", "bb", "ccc"], |a, b| a.len().cmp(&b.len())) // true
```

`ft_any` 가 "즉시 멈추는지"를 채점이 센다. `f` 를 몇 번 불렀는지 기록하는 클로저를 넘긴다.

`for i in 0..tab.len()` 처럼 인덱스로 돌면서 `tab[i]` 만 쓰면 clippy 가 `needless_range_loop` 경고를 낸다. `for x in tab` 으로 바로 돈다.

---

## ex02 : make_counter, make_adder, call_n_times

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

클로저를 만들어 돌려주고, 클로저를 받아 부른다.

```rust
pub fn make_counter() -> impl FnMut() -> u32
pub fn make_adder(n: i32) -> impl Fn(i32) -> i32
pub fn call_n_times<F: FnMut()>(n: usize, f: F)
```

- `make_counter` 가 돌려준 클로저는 부를 때마다 1, 2, 3, ... 을 돌려준다. 카운터끼리는 서로 독립이다.
- `make_adder(n)` 이 돌려준 클로저는 받은 값에 n 을 더한다.
- `call_n_times` 는 `f` 를 n 번 부른다.

```rust
let mut c = make_counter();
c(); c();
c()                // 3
make_adder(5)(10)  // 15
```

`make_counter` 안의 카운트 변수는 함수가 끝나면 사라질 지역 변수다. 클로저가 그 변수를 빌리기만 하면 사라진 변수를 가리키게 된다. 그래서 컴파일러가 막는다. `move` 를 붙이면 클로저가 변수를 통째로 가져가 자기 안에 보관한다.

`impl FnMut() -> u32` 는 "이름은 말 못 하지만 이 약속을 지키는 타입"이라는 뜻이다. 클로저마다 타입이 따로 있고 그 이름은 쓸 수 없기 때문에 이렇게 적는다.

---

## ex03 : compose, apply_n

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn compose<A, B, C>(f: impl Fn(A) -> B, g: impl Fn(B) -> C) -> impl Fn(A) -> C
pub fn apply_n<T>(f: impl Fn(T) -> T, n: usize, x: T) -> T
```

- `compose(f, g)` 는 **f 를 먼저**, 그 결과에 g 를 적용하는 함수를 돌려준다.
- `apply_n(f, n, x)` 는 x 에 f 를 n 번 적용한 값이다. n 이 0 이면 x 그대로다.

```rust
let h = compose(|x: i32| x + 1, |x: i32| x * 2);
h(3)                       // 8
compose(|s: &str| s.len(), |n: usize| n % 2 == 0)("ab") // true
apply_n(|x| x * 2, 10, 1)  // 1024
```

`compose` 가 돌려준 함수는 여러 번 불린다. 그래서 `f` 와 `g` 를 `FnOnce` 가 아닌 `Fn` 으로 받는다. 돌려줄 클로저에는 `f` 와 `g` 를 `move` 로 넣어야 한다.

`apply_n` 은 `T` 가 `Copy` 가 아니어도 된다. `String` 도 들어온다. 값을 f 에 넘기고 돌려받는 흐름을 생각한다.

---

## ex04 : 반복문 없이

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `for`, `while`, `loop` (단어 단위, 주석 포함) |

이번엔 반대다. 반복문을 쓰지 않고 반복자 메서드만으로 만든다.

```rust
pub fn sum_of_odd_squares(v: &[i64]) -> i64
pub fn word_lengths(s: &str) -> Vec<usize>
pub fn longest_word(s: &str) -> Option<&str>
pub fn count_vowels(s: &str) -> usize
```

| 함수 | 돌려줄 값 |
|------|-----------|
| `sum_of_odd_squares` | 홀수만 골라 제곱해 더한 값. 음수 홀수도 홀수다 |
| `word_lengths` | 공백으로 나눈 단어마다 글자 수(char 개수) |
| `longest_word` | 글자 수가 가장 많은 단어. 같으면 **앞의 것**. 단어가 없으면 `None` |
| `count_vowels` | 영문 모음 `aeiouAEIOU` 의 개수 |

```rust
sum_of_odd_squares(&[1, 2, 3, 4, 5])  // 1 + 9 + 25 = 35
word_lengths("the quick  brown")      // [3, 5, 5]
longest_word("one two six")           // Some("one")
count_vowels("Hello, World")          // 3
```

"공백"은 스페이스, 탭, 줄바꿈을 모두 포함한다. 공백이 여러 개 이어져도 빈 단어는 없다. `split_whitespace` 를 찾아본다.

`max_by_key` 는 같은 값이 여럿이면 **마지막** 것을 돌려준다. 앞의 것이 필요하면 방법을 궁리한다.

반복자는 게으르다(lazy). `filter` 와 `map` 만 이어 붙이면 아무 일도 일어나지 않는다. `sum`, `count`, `collect` 처럼 값을 끝까지 당기는 메서드가 마지막에 와야 실제로 돈다.

---

## ex05 : group_runs, rle

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

연속으로 같은 값을 묶는다. 이것으로 간단한 압축(run-length encoding)을 만든다.

```rust
pub fn group_runs<T: PartialEq + Clone>(v: &[T]) -> Vec<(T, usize)>
pub fn rle_encode(s: &str) -> String
pub fn rle_decode(s: &str) -> String
```

- `group_runs` 는 연속된 같은 값을 `(값, 개수)` 로 묶는다. 떨어져 있는 같은 값은 따로 센다.
- `rle_encode` 는 글자(char)마다 `글자 + 개수` 를 이어 붙인다. 개수가 1 이어도 쓴다.
- `rle_decode` 는 그 반대다. 개수는 두 자리 이상일 수 있다.

```rust
group_runs(&[1, 1, 2, 3, 3, 3, 1]) // [(1, 2), (2, 1), (3, 3), (1, 1)]
rle_encode("aaabccdddd")          // "a3b1c2d4"
rle_encode("가가나")               // "가2나1"
rle_decode("z12")                 // "zzzzzzzzzzzz"
```

`rle_decode` 에는 `rle_encode` 가 만든 문자열만 들어온다. 원래 문자열에는 숫자가 없다고 가정한다.

반복문과 반복자 중 무엇을 써도 된다. 읽기 쉬운 쪽을 고른다. `rle_decode` 는 "다음 글자를 꺼내지 않고 엿보기"가 필요하다. `peekable` 을 찾아본다.

---

## ex06 : Pairs

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module06/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `.windows(`, `.tuple_windows(`, `.zip(` |

나만의 반복자 어댑터를 만든다. 이웃한 두 원소를 짝으로 내는 `pairs()` 다.

```rust
pub struct Pairs<I: Iterator> { /* 비공개 필드 */ }

pub trait PairsExt: Iterator + Sized {
    fn pairs(self) -> Pairs<Self>;
}

impl<I: Iterator> PairsExt for I { /* ... */ }

impl<I> Iterator for Pairs<I>
where
    I: Iterator,
    I::Item: Clone,
{
    type Item = (I::Item, I::Item);
    /* ... */
}
```

```rust
use ex06::PairsExt;

vec![1, 2, 3, 4].into_iter().pairs().collect::<Vec<_>>() // [(1, 2), (2, 3), (3, 4)]
"abc".chars().pairs().next()                           // Some(('a', 'b'))
vec![7].into_iter().pairs().next()                     // None
(1..).pairs().take(2).collect::<Vec<_>>()              // [(1, 2), (2, 3)]
```

`pairs()` 를 부르는 순간에는 원본에서 아무것도 꺼내지 않는다. 표준 어댑터처럼 게을러야 한다. 채점이 이것을 확인한다.

여기서 두 가지를 배운다.

- 어댑터의 정체: `map`, `filter` 도 다른 반복자를 품은 구조체일 뿐이다. `next` 가 불릴 때 안쪽 반복자의 `next` 를 불러 가공한다.
- 확장 트레이트: `impl<I: Iterator> PairsExt for I` 한 줄로 세상의 모든 반복자에 `.pairs()` 가 생긴다. 쓰는 쪽은 `use ex06::PairsExt;` 로 트레이트를 가져와야 메서드가 보인다.

`(a, b)` 다음 짝은 `(b, c)` 다. `b` 는 두 번 나가므로 `Clone` 이 필요하다. `Option::take` 와 `Option::replace` 가 쓸모 있다.

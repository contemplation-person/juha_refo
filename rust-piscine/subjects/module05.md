# Module 05 — 제네릭과 트레이트

> 같은 코드를 여러 타입에 쓰는 법(제네릭)과, 타입이 할 수 있는 일을 약속하는 법(트레이트)을 익힌다.

읽을거리: The Rust Book 10.1, 10.2장, "Advanced Traits" 절의 연산자 오버로딩 부분 (`rustup doc --book`)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module05/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.
- 이 모듈은 모두 라이브러리다. `cargo new --vcs none --lib exNN` 으로 만든다.

트레이트는 "이 타입은 이런 일을 할 수 있다"는 약속이다. 제네릭 함수는 "약속만 지키면 어떤 타입이든 받는다"고 말한다. 둘을 잇는 것이 트레이트 바운드(`T: PartialOrd`)다.

---

## ex00 : largest

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `max(`, `max_by(`, `max_by_key(`, `cmp::`, `.fold(`, `.reduce(` |

슬라이스에서 가장 큰 값을 돌려주는 제네릭 함수를 만든다. 비어 있으면 `None` 이다.

```rust
pub fn largest<T: PartialOrd + Copy>(list: &[T]) -> Option<T>
```

```rust
largest(&[34, 50, 25, 100, 65]) // Some(100)
largest(&[1.5, -2.0, 3.25])     // Some(3.25)
largest(&['y', 'm', 'a'])       // Some('y')
largest::<i32>(&[])             // None
```

바운드가 왜 둘인지 생각한다.

- `PartialOrd` 가 없으면 `>` 로 비교할 수 없다. `f64` 는 `NaN` 때문에 `Ord` 가 아니라 `PartialOrd` 만 있다.
- `Copy` 가 없으면 슬라이스 안의 값을 꺼내 올 수 없다. 빌린 슬라이스에서 값을 가져가려면 복사해야 한다.

`?` 는 `Option` 에도 쓸 수 있다. `list.first()?` 는 비어 있으면 그 자리에서 `None` 을 돌려준다.

---

## ex01 : Stack

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

어떤 타입이든 담는 스택(나중에 넣은 것을 먼저 꺼내는 통)을 만든다. 안쪽 저장소는 `Vec<T>` 를 써도 된다. 필드는 공개하지 않는다.

```rust
pub struct Stack<T> { /* 비공개 필드 */ }

impl<T> Stack<T> {
    pub fn new() -> Self
    pub fn push(&mut self, item: T)
    pub fn pop(&mut self) -> Option<T>
    pub fn peek(&self) -> Option<&T>
    pub fn len(&self) -> usize
    pub fn is_empty(&self) -> bool
}

impl<T> Default for Stack<T>          // Stack::new() 와 같은 빈 스택
impl<T: Display> Display for Stack<T> // 아래 형식
```

`Display` 는 바닥부터 꼭대기 순서로 `[1, 2, 3]` 처럼 출력한다. 비어 있으면 `[]` 다.

```rust
let mut s = Stack::new();
s.push(1);
s.push(2);
s.peek();       // Some(&2)
s.to_string();  // "[1, 2]"
s.pop();        // Some(2)
```

핵심은 `impl<T: Display> Display for Stack<T>` 다. 출력은 `T` 가 출력 가능할 때만 생긴다. 출력할 수 없는 타입도 스택에는 담을 수 있어야 한다. 채점에 그런 테스트가 있다.

clippy 가 두 가지를 요구한다. 그래서 `Default` 와 `is_empty` 가 목록에 있다.

- `new_without_default`: 인자 없는 `new()` 가 있으면 `Default` 도 구현하라는 경고.
- `len_without_is_empty`: 공개 `len()` 이 있으면 `is_empty()` 도 두라는 경고.

`#[derive(Default)]` 는 `T: Default` 바운드를 몰래 붙인다. `Stack<NoDefault>` 같은 경우를 막고 싶지 않다면 직접 구현한다.

---

## ex02 : Summary

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

기본 구현이 있는 트레이트를 만든다.

```rust
pub trait Summary {
    fn author(&self) -> String;
    fn summarize(&self) -> String { /* 기본 구현 */ }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
}

pub struct Article {
    pub title: String,
    pub author: String,
    pub content: String,
}

pub fn notify(item: &impl Summary) -> String
```

| 대상 | `author()` | `summarize()` |
|------|------------|---------------|
| 기본 구현 | — | `"(Read more from {author}...)"` |
| `Tweet` | `"@{username}"` | 덮어쓴다: `"{author}: {content}"` |
| `Article` | `"{author}"` 필드 그대로 | 기본 구현을 그대로 쓴다 |

`notify` 는 `"Breaking news! {summarize}"` 를 돌려준다.

```rust
let t = Tweet { username: "ferris".into(), content: "hello".into() };
t.summarize();   // "@ferris: hello"
notify(&t);      // "Breaking news! @ferris: hello"
```

기본 구현 안에서 `self.author()` 를 부를 수 있다. 아직 구현되지 않은 메서드를 믿고 쓰는 셈이다. 트레이트를 구현하는 쪽이 `author` 를 반드시 채워야 하므로 안전하다.

채점에는 여러분이 모르는 타입도 `Summary` 를 구현해 `notify` 에 넘긴다. `notify` 는 특정 타입이 아니라 약속만 보고 일해야 한다.

---

## ex03 : Fraction

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

분수를 만들고 `Display` 로 출력한다.

```rust
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Fraction { /* 비공개 필드 */ }

impl Fraction {
    pub fn new(num: i64, den: i64) -> Fraction
    pub fn numerator(&self) -> i64
    pub fn denominator(&self) -> i64
}

impl fmt::Display for Fraction
```

`new` 는 항상 아래 규칙대로 정리해서 저장한다.

| 규칙 | 예 |
|------|----|
| 기약분수로 줄인다 | `new(6, 8)` → 3/4 |
| 부호는 분자에만 둔다. 분모는 늘 양수 | `new(1, -2)` → -1/2, `new(-3, -9)` → 1/3 |
| 0 은 0/1 | `new(0, -5)` → 0/1 |
| 분모가 0 이면 panic | `new(1, 0)` → panic |

`Display` 는 분모가 1 이면 분자만, 아니면 `분자/분모` 를 쓴다.

```rust
Fraction::new(10, -4).to_string() // "-5/2"
Fraction::new(8, 4).to_string()   // "2"
```

입력의 절댓값은 10억 이하다.

왜 만들 때 정리할까. 늘 같은 모양으로 저장하면 `2/4` 와 `1/2` 가 같은 필드값이 된다. 그래서 `#[derive(PartialEq)]` 만으로 비교가 맞게 된다. 이처럼 "항상 참인 조건"을 불변식(invariant)이라 부른다. 필드를 비공개로 두는 이유도 불변식을 밖에서 깨지 못하게 하기 위해서다.

`Display` 를 구현하면 `to_string()` 과 `format!("{}")` 이 공짜로 따라온다.

---

## ex04 : Vector2

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

2차원 벡터에 연산자를 붙인다.

```rust
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Vector2 {
    pub x: f64,
    pub y: f64,
}

impl Vector2 {
    pub fn new(x: f64, y: f64) -> Vector2
    pub fn dot(self, other: Vector2) -> f64   // x1*x2 + y1*y2
    pub fn length(self) -> f64                // 원점에서의 거리
}
```

| 식 | 구현할 트레이트 | 결과 |
|----|-----------------|------|
| `a + b` | `Add` | 성분끼리 더한다 |
| `a - b` | `Sub` | 성분끼리 뺀다 |
| `a * 2.0` | `Mul<f64>` | 두 성분에 곱한다 |
| `-a` | `Neg` | 두 성분의 부호를 바꾼다 |
| `a += b` | `AddAssign` | `a = a + b` |

```rust
let p = Vector2::new(0.0, 0.0);
let v = Vector2::new(1.0, 2.0);
p + v * 3.0 - Vector2::new(1.0, 1.0) // Vector2 { x: 2.0, y: 5.0 }
```

러스트의 `+` 는 `std::ops::Add::add` 를 부르는 문법일 뿐이다. 트레이트를 구현하면 내 타입에도 `+` 가 생긴다. `type Output` 은 연산 결과의 타입이다.

`Copy` 가 있으므로 `a + a` 처럼 같은 값을 두 번 써도 된다. `Copy` 를 빼면 첫 `a` 가 이동(move)해 버려 컴파일되지 않는다.

`2.0 * a` 는 요구하지 않는다. 그건 `f64` 쪽에 `Mul<Vector2>` 를 구현해야 하는 별개의 일이다.

---

## ex05 : Shape

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

서로 다른 타입을 한 `Vec` 에 담는다. 트레이트 객체(`dyn Trait`)를 쓴다.

```rust
pub trait Shape {
    fn area(&self) -> f64;
    fn name(&self) -> String;
}

pub struct Circle { pub radius: f64 }
pub struct Square { pub side: f64 }
pub struct Triangle { pub base: f64, pub height: f64 }

pub fn total_area(shapes: &[Box<dyn Shape>]) -> f64
pub fn largest_name(shapes: &[Box<dyn Shape>]) -> Option<String>
```

| 타입 | `area()` | `name()` |
|------|----------|----------|
| `Circle` | π × r² (`std::f64::consts::PI`) | `"circle"` |
| `Square` | side² | `"square"` |
| `Triangle` | base × height ÷ 2 | `"triangle"` |

- `total_area` 는 넓이의 합이다. 비어 있으면 0.0 이다.
- `largest_name` 은 넓이가 가장 큰 도형의 이름이다. 비어 있으면 `None` 이다. 넓이가 같으면 **앞에 있는 것**을 고른다.

```rust
let shapes: Vec<Box<dyn Shape>> = vec![
    Box::new(Square { side: 1.0 }),
    Box::new(Circle { radius: 1.0 }),
];
largest_name(&shapes) // Some("circle")
```

ex00 의 제네릭은 컴파일할 때 타입마다 함수를 따로 찍어 낸다. 그래서 `Vec<T>` 에는 한 타입만 담긴다. `Box<dyn Shape>` 는 "넓이와 이름을 알려 주는 무언가"를 가리키는 포인터다. 크기가 다른 값들도 포인터로 감싸면 한 줄로 세울 수 있다. 대신 메서드는 실행 중에 표(vtable)를 보고 찾아간다.

채점에는 여러분이 모르는 도형도 섞여 들어간다.

---

## ex06 : Countdown, Fibonacci

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module05/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

`Iterator` 트레이트를 직접 구현한다.

```rust
pub struct Countdown { /* 비공개 필드 */ }
impl Countdown {
    pub fn new(from: u32) -> Countdown
}
impl Iterator for Countdown { type Item = u32; /* ... */ }

pub struct Fibonacci { /* 비공개 필드 */ }
impl Fibonacci {
    pub fn new() -> Fibonacci
}
impl Default for Fibonacci   // new() 와 같다
impl Iterator for Fibonacci { type Item = u64; /* ... */ }
```

- `Countdown::new(3)` 은 3, 2, 1 을 내고 끝난다. `Countdown::new(0)` 은 아무것도 내지 않는다.
- `Fibonacci::new()` 는 0, 1, 1, 2, 3, 5, ... 를 낸다. `u64` 에 담을 수 없는 값에 닿으면 끝난다. fibonacci(0) 부터 fibonacci(93) 까지 94개를 내고 그 뒤로는 계속 `None` 이다.

```rust
Countdown::new(100).sum::<u32>()          // 5050
Fibonacci::new().take(5).collect::<Vec<_>>() // [0, 1, 1, 2, 3]
Fibonacci::new().count()                  // 94
```

`Iterator` 를 구현할 때 직접 쓰는 것은 `next` 하나뿐이다. `sum`, `take`, `filter`, `count` 같은 수십 개 메서드는 `next` 만 있으면 기본 구현으로 따라온다. ex02 의 기본 구현과 같은 원리다.

module00 ex07 의 넘침 함정이 여기서 다시 나온다. `checked_add` 는 넘치면 panic 대신 `None` 을 돌려준다.

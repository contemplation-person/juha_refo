# Module 02 — 구조체, 열거형, match

> 관련 있는 값은 구조체로 묶는다. "이것 아니면 저것"은 열거형으로 표현한다. 열거형을 다룰 때는 match 로 모든 경우를 빠짐없이 처리한다.

읽을거리: The Rust Book 5장, 6장

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module02/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.

이 모듈의 과제는 모두 라이브러리다. 채점 코드가 바깥에서 쓰므로 타입, 필드, 메서드는 모두 `pub` 이어야 한다.

---

## ex00 : Point

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Point {
    pub x: f64,
    pub y: f64,
}

impl Point {
    pub fn new(x: f64, y: f64) -> Point
    pub fn origin() -> Point
    pub fn distance(&self, other: &Point) -> f64
    pub fn translate(&mut self, dx: f64, dy: f64)
}
```

| 메서드 | 하는 일 |
|--------|---------|
| `new` | 주어진 좌표의 점을 만든다 |
| `origin` | `(0, 0)` 점을 만든다 |
| `distance` | 두 점 사이의 직선거리 |
| `translate` | 점 자신을 `(dx, dy)` 만큼 옮긴다 |

`self` 가 없는 `new`, `origin` 은 연관 함수다. `Point::new(1.0, 2.0)` 처럼 타입 이름으로 부른다. `&self` 는 읽기만, `&mut self` 는 고치기까지 하는 메서드다.

`#[derive(...)]` 는 컴파일러에게 기본 구현을 맡기는 표시다. `Debug` 가 있어야 `{:?}` 로 찍을 수 있다. `PartialEq` 가 있어야 `==` 로 비교할 수 있다. `Copy` 가 있으면 대입할 때 이동(move) 대신 복사가 일어난다.

거리는 피타고라스 정리로 구한다. `f64` 에는 `.sqrt()` 가 있다.

---

## ex01 : Rectangle

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
#[derive(Debug, PartialEq)]
pub struct Rectangle {
    pub width: u32,
    pub height: u32,
}

impl Rectangle {
    pub fn new(width: u32, height: u32) -> Rectangle
    pub fn square(size: u32) -> Rectangle
    pub fn area(&self) -> u64
    pub fn perimeter(&self) -> u64
    pub fn can_hold(&self, other: &Rectangle) -> bool
}
```

| 메서드 | 하는 일 |
|--------|---------|
| `square` | 가로세로가 같은 사각형을 만든다 |
| `area` | 넓이 |
| `perimeter` | 둘레 |
| `can_hold` | `other` 가 가로, 세로 모두 자신보다 **작으면** `true` |

`can_hold` 는 크기가 같으면 `false` 다. 딱 맞는 것은 "안에 넣을 수 있다"로 보지 않는다.

`area` 가 `u64` 를 돌려주는 이유가 있다. `u32` 끼리 곱하면 결과도 `u32` 라서 금방 넘친다. 채점에는 `u32::MAX × u32::MAX` 도 나온다. 곱하기 전에 `as u64` 로 넓혀야 한다. 곱한 뒤에 넓히면 이미 늦다.

---

## ex02 : Shape

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `3.14` |

```rust
pub enum Shape {
    Circle { radius: f64 },
    Rectangle { width: f64, height: f64 },
    Triangle { a: f64, b: f64, c: f64 },
}

impl Shape {
    pub fn area(&self) -> f64
    pub fn perimeter(&self) -> f64
}
```

도형마다 넓이와 둘레를 구한다. 삼각형은 세 변의 길이만 주어진다. 넓이는 헤론의 공식으로 구한다.

```
s = (a + b + c) / 2
넓이 = √( s × (s−a) × (s−b) × (s−c) )
```

열거형의 각 갈래(variant)는 서로 다른 데이터를 품을 수 있다. `match self { Shape::Circle { radius } => ... }` 처럼 갈래를 고르면서 안의 값을 꺼낸다. 갈래 하나를 빠뜨리면 컴파일러가 막는다. 이것이 match 의 핵심이다.

원주율은 직접 쓰지 않는다. `std::f64::consts::PI` 를 쓴다. `3.14159` 같은 값을 직접 쓰면 clippy 가 `approx_constant` 로 막는다.

채점은 소수 오차 `1e-9` 까지 허용한다.

---

## ex03 : Option

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `checked_`, `overflowing_`, `wrapping_`, `.position(`, `.find(`, `.rfind(`, `.contains(` |

```rust
pub fn safe_div(a: i32, b: i32) -> Option<i32>
pub fn find_index(haystack: &[i32], needle: i32) -> Option<usize>
pub fn add_options(a: Option<i32>, b: Option<i32>) -> Option<i32>
```

| 함수 | 돌려줄 값 |
|------|-----------|
| `safe_div` | 나눌 수 있으면 `Some(몫)`, 아니면 `None` |
| `find_index` | `needle` 이 처음 나오는 위치. 없으면 `None` |
| `add_options` | 둘 다 `Some` 이면 `Some(합)`, 하나라도 `None` 이면 `None` |

러스트에는 null 이 없다. "값이 없을 수도 있다"는 `Option` 으로 타입에 드러낸다. 받는 쪽은 `None` 을 처리하지 않으면 값을 꺼낼 수 없다.

`safe_div` 가 `None` 을 돌려야 하는 경우는 둘이다. 0 으로 나눌 때 하나는 쉽게 떠오른다. 나머지 하나는 i32 의 범위를 생각한다. i32 는 `-2147483648` 부터 `2147483647` 까지다. `i32::MIN / -1` 의 답은 이 범위에 들어가는가?

`add_options` 는 두 값을 튜플로 묶어 `match (a, b)` 로 풀면 짧다. 채점 값은 넘치지 않는다.

---

## ex04 : Light

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Light {
    Red,
    Yellow,
    Green,
}

impl Light {
    pub fn next(self) -> Light
    pub fn duration(&self) -> u32
    pub fn can_go(&self) -> bool
    pub fn after(start: Light, seconds: u32) -> Light
}
```

신호등은 `Red → Green → Yellow → Red` 순서로 돈다.

| 신호 | `duration` (초) | `can_go` |
|------|-----------------|----------|
| `Red` | 60 | `false` |
| `Green` | 45 | `true` |
| `Yellow` | 5 | `false` |

`after(start, seconds)` 는 `start` 신호가 막 켜진 순간부터 `seconds` 초가 지났을 때의 신호를 돌려준다.

```rust
Light::after(Light::Red, 59)  // Red
Light::after(Light::Red, 60)  // Green
Light::after(Light::Red, 110) // Red  (한 바퀴 돎)
```

채점에는 `u32::MAX` 초도 나온다. 한 바퀴는 몇 초인가? 그 수로 나눈 나머지만 보면 된다. 지난 시간을 계속 더해 가는 방식은 넘칠 수 있다.

`next` 가 `&self` 가 아니라 `self` 를 받아도 되는 이유는 `Copy` 다. 복사가 싸니 값째 넘긴다.

---

## ex05 : Temperature

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub enum Temperature {
    Celsius(f64),
    Fahrenheit(f64),
    Kelvin(f64),
}

impl Temperature {
    pub fn to_celsius(&self) -> f64
    pub fn describe(&self) -> &'static str
}
```

`to_celsius` 는 섭씨로 바꾼다.

```
섭씨 = (화씨 − 32) × 5 / 9
섭씨 = 켈빈 − 273.15
```

`describe` 는 섭씨 값 c 를 기준으로 고른다. 위에서부터 처음 맞는 줄을 쓴다.

| 조건 | 돌려줄 값 |
|------|-----------|
| c < -273.15 | `"impossible"` |
| c < 0 | `"freezing"` |
| c < 15 | `"cold"` |
| c < 25 | `"mild"` |
| 그 외 | `"hot"` |

match 의 갈래에는 조건을 붙일 수 있다(match guard). `c if c < 0.0 => ...` 꼴이다. 갈래는 위에서부터 검사하므로 순서가 곧 의미다.

`&'static str` 은 프로그램 안에 박혀 끝까지 살아 있는 문자열이다. `"hot"` 같은 리터럴이 그렇다. 그래서 새 `String` 을 만들지 않고 돌려줄 수 있다.

---

## ex06 : Robot

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module02/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

pub struct Robot {
    pub x: i32,
    pub y: i32,
    pub facing: Direction,
}

impl Robot {
    pub fn new(x: i32, y: i32, facing: Direction) -> Robot
    pub fn turn_left(&mut self)
    pub fn turn_right(&mut self)
    pub fn advance(&mut self)
    pub fn execute(&mut self, instructions: &str)
}
```

격자 위의 로봇을 움직인다. 북쪽이 y 가 커지는 쪽, 동쪽이 x 가 커지는 쪽이다.

| 메서드 | 하는 일 |
|--------|---------|
| `turn_left` | 제자리에서 왼쪽으로 90도 돈다 |
| `turn_right` | 제자리에서 오른쪽으로 90도 돈다 |
| `advance` | 바라보는 방향으로 한 칸 간다 |
| `execute` | 문자열의 글자를 차례로 실행한다. `L` 왼쪽, `R` 오른쪽, `A` 전진. 다른 글자는 무시한다 |

```rust
let mut r = Robot::new(7, 3, Direction::North);
r.execute("RAALAL");
// r.x == 9, r.y == 4, r.facing == Direction::West
```

구조체(로봇의 상태)와 열거형(방향)을 함께 쓰는 과제다. `execute` 는 이미 만든 메서드를 다시 부르면 된다. 같은 일을 두 번 쓰지 않는다.

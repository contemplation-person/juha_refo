# Module 08 — 동시성

> 일을 여러 스레드에 나눠 맡긴다. 러스트는 "같이 쓰면 위험한 것"을 컴파일 때 막는다. 그 규칙이 왜 있는지 몸으로 익힌다.

읽을거리: The Rust Book 16장, 21장 (스레드 풀)

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module08/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.
- 이 모듈은 전부 라이브러리다. `cargo new --vcs none --lib exNN` 으로 만든다.

스레드 과제에서 가장 흔한 실패는 "끝나지 않음"이다. 누군가를 영원히 기다리면 시간 제한(10초)에 걸린다. 결과가 `시간 초과` 면 "누가 무엇을 기다리는가"부터 따져 본다.

---

## ex00 : spawn_squares

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module08/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
use std::thread::JoinHandle;

pub fn spawn_squares(n: u64) -> Vec<JoinHandle<u64>>
```

`0` 부터 `n - 1` 까지 i 마다 스레드를 하나씩 띄운다. i 번째 스레드는 `i * i` 를 계산해 돌려준다. 띄운 순서대로 손잡이(`JoinHandle`)를 모아 돌려준다. 기다리는(`join`) 일은 부르는 쪽이 한다.

```rust
let handles = spawn_squares(4);
let results: Vec<u64> = handles.into_iter().map(|h| h.join().unwrap()).collect();
// [0, 1, 4, 9]
```

`thread::spawn(|| i * i)` 처럼 쓰면 "클로저가 `i` 를 빌리는데, `i` 가 스레드보다 먼저 사라질 수 있다"는 에러가 난다. 새 스레드는 언제 끝날지 모른다. 그래서 `spawn` 은 빌린 것 없이 스스로 살 수 있는(`'static`) 클로저만 받는다. `move` 를 붙이면 `i` 를 클로저 안으로 복사해 넣는다.

---

## ex01 : parallel_sum

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module08/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn parallel_sum(numbers: &[u64], threads: usize) -> u64
```

`numbers` 를 최대 `threads` 조각으로 나눈다. 조각마다 스레드 하나가 합을 구한다. 조각 합을 다시 더해 돌려준다.

- `threads` 는 1 이상이다.
- `numbers` 가 비어 있으면 0 이다.
- `threads` 가 숫자 개수보다 많을 수도 있다. 빈 조각을 만들 필요는 없다.

```rust
parallel_sum(&[1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 3) // 55
```

이번에는 ex00 의 `move` 로 풀리지 않는다. 조각은 `numbers` 를 빌린 것이고, `numbers` 는 부르는 쪽 것이다. `thread::spawn` 은 스레드가 함수보다 오래 살 수 있다고 보고 거절한다.

`std::thread::scope` 는 "이 블록이 끝나기 전에 안의 스레드는 모두 끝난다"를 보장한다. 그 약속 덕분에 블록 바깥 값을 빌려 줄 수 있다. 조각 크기는 `numbers.len().div_ceil(threads)` 처럼 올림 나눗셈으로 정하면 편하다. 슬라이스의 `chunks` 도 찾아본다.

---

## ex02 : channels

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module08/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

스레드끼리 값을 주고받는 통로(채널)를 쓴다.

```rust
use std::sync::mpsc::Receiver;

pub fn start_producer(items: Vec<String>) -> Receiver<String>
pub fn fan_in(producers: usize, per_producer: usize) -> Vec<(usize, usize)>
```

`start_producer` 는 스레드 하나를 띄우고 바로 받는 쪽(`Receiver`)을 돌려준다. 그 스레드는 `items` 를 순서대로 보낸다. 부르는 쪽은 `for item in rx` 로 받는다. 다 보내면 반복이 끝나야 한다.

`fan_in` 은 보내는 스레드를 `producers` 개 띄운다. id 가 `p` 인 스레드는 `(p, 0)`, `(p, 1)`, ..., `(p, per_producer - 1)` 을 보낸다. 받은 것을 모두 모아 정렬해서 돌려준다.

```rust
fan_in(2, 2) // [(0, 0), (0, 1), (1, 0), (1, 1)]
```

받는 쪽 반복은 "보내는 쪽(`Sender`)이 하나도 남지 않았을 때" 끝난다. 아직 보낼 사람이 있을 수 있는데 끝낼 수는 없기 때문이다.

`fan_in` 에서는 `Sender` 를 스레드마다 `clone` 해서 준다. 그런데 처음 만든 원본 `Sender` 가 함수 안에 그대로 남아 있으면 반복이 영원히 끝나지 않는다. 원본은 아무것도 보내지 않지만 살아 있기 때문이다. 다 나눠 준 뒤 `drop` 한다. `시간 초과` 가 나면 여기부터 의심한다.

스레드마다 도착 순서는 실행할 때마다 다르다. 그래서 정렬해서 돌려준다.

---

## ex03 : shared_counter

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module08/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `Atomic`, `mpsc`, `scope` |

```rust
pub fn count_together(threads: usize, increments: usize) -> usize
pub fn collect_ids(threads: usize) -> Vec<usize>
```

`count_together` 는 스레드를 `threads` 개 띄운다. 모든 스레드가 하나의 공유 카운터를 `increments` 번씩 1 올린다. 모두 끝나면 카운터 값을 돌려준다. 답은 언제나 `threads * increments` 여야 한다.

`collect_ids` 는 스레드를 `threads` 개 띄운다. id 가 `i` 인 스레드는 공유 `Vec` 에 `i` 를 넣는다. 모두 끝나면 정렬해서 돌려준다.

`thread::spawn` 과 `Arc<Mutex<...>>` 로 푼다. `scope` 는 금지다.

왜 `Mutex` 일까. "읽고, 1 더하고, 쓰기"는 세 단계다. 두 스레드가 같은 값을 읽고 각자 1 을 더해 쓰면 한 번이 사라진다. `Mutex` 는 열쇠가 하나뿐인 방이다. `lock()` 으로 열쇠를 받은 스레드만 값을 만진다. 열쇠는 `lock()` 이 돌려준 값이 사라질 때 자동으로 반납된다.

왜 `Rc` 가 아니라 `Arc` 일까. `Rc` 의 주인 수 세기는 한 스레드만 쓴다고 가정해 빠르게 만들었다. 두 스레드가 동시에 세면 수가 틀어진다. 그래서 `Rc` 는 `Send` 가 아니고, 스레드로 넘기려 하면 컴파일 에러가 난다. `Arc` 는 원자적(atomic)으로 세는 `Rc` 다. 조금 느리지만 여러 스레드가 동시에 세어도 맞다. 직접 `Rc` 로 바꿔 에러 메시지를 읽어 본다.

---

## ex04 : thread_pool

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module08/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `scope` |

일꾼 스레드를 미리 정해진 수만큼 띄워 두고 일을 나눠 주는 스레드 풀을 만든다.

```rust
pub struct ThreadPool { /* 자유 */ }

impl ThreadPool {
    pub fn new(size: usize) -> ThreadPool
    pub fn execute<F>(&self, f: F)
    where
        F: FnOnce() + Send + 'static;
}

impl Drop for ThreadPool { /* 직접 구현 */ }
```

- `new` 는 일꾼 스레드를 정확히 `size` 개 띄운다. `size` 가 0 이면 panic 한다.
- `execute` 는 일을 맡기고 바로 돌아온다. 일은 일꾼 중 하나가 한다. 부르는 스레드가 직접 하면 안 된다.
- 풀이 `drop` 될 때는 맡긴 일이 모두 끝나고, 일꾼 스레드도 모두 끝날 때까지 기다린다.

채점이 보는 것은 셋이다.

| 검사 | 틀리면 |
|------|--------|
| 맡긴 100개가 `drop` 전에 모두 실행되는가 | 테스트 실패 |
| 일 4개가 동시에 도는가 (4개가 서로를 기다리는 일) | 시간 초과 |
| 일꾼이 `size` 개를 넘지 않고, 부르는 스레드는 일하지 않는가 | 테스트 실패 |

뼈대는 이렇다. 일은 `Box<dyn FnOnce() + Send + 'static>` 로 감싸 채널로 보낸다. 받는 쪽 `Receiver` 는 하나뿐이고 복제할 수 없다. 일꾼 여럿이 나눠 쓰도록 `Arc<Mutex<Receiver<...>>>` 로 감싼다.

`Drop` 에서 일꾼을 `join` 만 하면 영원히 기다린다. 일꾼은 "다음 일"을 기다리며 `recv()` 에 멈춰 있기 때문이다. 먼저 `Sender` 를 버린다. 그러면 `recv()` 가 에러를 돌려주고, 일꾼은 그걸 "퇴근 신호"로 보고 반복을 빠져나온다. `Sender` 를 `Option` 에 담아 두면 `take()` 로 꺼내 버릴 수 있다.

일꾼 안에서 `rx.lock().unwrap().recv()` 의 결과를 먼저 변수에 받고 나서 일을 실행한다. 열쇠를 쥔 채로 일을 실행하면 다른 일꾼이 아무도 다음 일을 받지 못한다. 그러면 동시 실행 검사에서 멈춘다.

# Module 07 — 수명과 스마트 포인터

> 빌린 값이 "언제까지 살아 있는가"를 컴파일러에게 알려 주는 법. 그리고 `Box`, `Rc`, `RefCell`, `Weak` 로 상자 안에 값을 담아 서로 잇는 법.

읽을거리: The Rust Book 10.3절, 15장

공통 규칙은 [README](../README.md#규칙)를 따른다. 특히 다음을 기억한다.

- 과제마다 `rendu/module07/exNN/` 에 크레이트 하나를 만든다.
- 패키지 이름은 디렉터리 이름과 같다 (`ex00`, `ex01`, ...).
- 채점은 ex00 부터 순서대로 한다. 하나라도 틀리면 그 뒤는 보지 않는다.
- 이 모듈은 전부 라이브러리다. `cargo new --vcs none --lib exNN` 으로 만든다.

구조체에 `pub fn new() -> Self` 를 만들면 clippy 가 `new_without_default` 경고를 낸다. "인자 없는 `new` 가 있으면 `Default` 도 있어야 자연스럽다"는 뜻이다. 구조체 위에 `#[derive(Default)]` 를 붙이면 해결된다.

---

## ex00 : longest

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex00/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

```rust
pub fn longest<'a>(a: &'a str, b: &'a str) -> &'a str
```

두 문자열 중 바이트 길이(`len()`)가 긴 쪽을 돌려준다. 길이가 같으면 `a` 를 돌려준다.

새 문자열을 만들어 돌려주면 안 된다. 받은 두 조각 중 하나를 그대로 돌려준다. 채점은 돌려준 값이 입력과 같은 메모리를 가리키는지도 본다.

`<'a>` 를 지우고 컴파일해 본다. 컴파일러는 "돌려주는 참조가 `a` 에서 왔는지 `b` 에서 왔는지 모른다"고 불평한다. `'a` 는 "돌려주는 값은 둘 중 더 짧게 사는 쪽만큼만 믿어라"라는 약속이다. 수명 표시는 값을 오래 살게 만들지 않는다. 이미 있는 관계를 컴파일러에게 설명할 뿐이다.

---

## ex01 : Words

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex01/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

문장을 단어 하나씩 잘라 주는 구조체를 만든다. 구조체는 원문을 복사하지 않고 빌려서 들고 있는다.

```rust
pub struct Words<'a> { /* 자유 */ }

impl<'a> Words<'a> {
    pub fn new(text: &'a str) -> Self
    pub fn next_word(&mut self) -> Option<&'a str>
}
```

- 단어는 ASCII 공백(`' '`, `'\t'`, `'\n'` 등)으로 나뉜다. 공백이 여러 개 이어져도 된다.
- 단어가 더 없으면 `None` 을 돌려준다. 그 뒤로 몇 번을 불러도 `None` 이다.
- 돌려주는 단어는 원문의 조각이어야 한다. `String` 을 새로 만들지 않는다.

```rust
let text = String::from("  hello   rust ");
let mut w = Words::new(&text);
w.next_word() // Some("hello")
w.next_word() // Some("rust")
w.next_word() // None
```

반환형의 `'a` 가 핵심이다. 채점은 아래 코드가 컴파일되는지 본다.

```rust
let word;
{
    let mut w = Words::new(&text);
    word = w.next_word().unwrap();
}   // w 는 여기서 사라진다
println!("{word}"); // 그래도 word 는 text 를 빌린 것이라 살아 있다
```

반환형을 `Option<&str>` 로만 쓰면 수명 생략 규칙에 따라 `&mut self` 에 묶인다. 그러면 단어가 `w` 보다 오래 살 수 없어 위 코드가 컴파일되지 않는다. 단어는 `Words` 가 아니라 원문 `text` 에서 빌린 것이다. 그 사실을 `'a` 로 적어 준다.

---

## ex02 : ft_list

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex02/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `Vec`, `vec!`, `VecDeque`, `LinkedList`, `collections` |

연결 리스트를 직접 만든다. 구조는 아래와 똑같이 둔다. 채점이 필드에 직접 접근한다.

```rust
pub struct Node {
    pub data: i32,
    pub next: Option<Box<Node>>,
}

pub struct List {
    pub head: Option<Box<Node>>,
}

impl List {
    pub fn new() -> Self                    // 빈 리스트
    pub fn push_front(&mut self, data: i32) // 맨 앞에 추가
    pub fn push_back(&mut self, data: i32)  // 맨 뒤에 추가
    pub fn size(&self) -> usize             // 노드 개수
    pub fn last(&self) -> Option<i32>       // 마지막 값, 비었으면 None
    pub fn at(&self, index: usize) -> Option<i32> // 0부터 센 index 번째 값
}
```

`List::default()` 도 빈 리스트여야 한다.

왜 그냥 `next: Option<Node>` 가 아닐까. 컴파일러는 구조체 크기를 미리 알아야 한다. `Node` 안에 `Node` 가 통째로 들어가면 크기가 끝없이 커진다. `Box` 는 "값은 힙에 두고 여기엔 주소만 둔다"는 뜻이다. 주소는 크기가 정해져 있다.

`push_front` 에서 `self.head` 를 새 노드로 옮기려 하면 "빌린 것에서 꺼낼 수 없다"는 에러가 난다. 빌린 자리를 잠깐이라도 비워 둘 수 없기 때문이다. `Option::take()` 는 값을 꺼내고 그 자리에 `None` 을 넣는다. 자리가 비지 않으니 허락된다.

`push_back` 은 `&mut` 참조를 한 칸씩 옮겨 가며 끝을 찾는다. `while let Some(node) = cur { cur = &mut node.next; }` 모양을 떠올려 본다.

---

## ex03 : ft_list_ops

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex03/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `Vec`, `vec!`, `VecDeque`, `LinkedList`, `collections` |

ex02 의 `Node`, `List` 를 그대로 가져온다. `new` 와 `push_front` 도 다시 만든다. 그리고 아래 두 함수를 더한다.

```rust
impl List {
    pub fn reverse(&mut self)              // 노드 순서를 뒤집는다
    pub fn remove_if(&mut self, data: i32) // data 와 같은 노드를 모두 지운다
}
```

```
reverse:    1 → 2 → 3      ⇒   3 → 2 → 1
remove_if(9): 9 → 1 → 9 → 9 → 2   ⇒   1 → 2
```

`reverse` 는 새 노드를 만들지 않는다. 있는 노드의 `next` 만 바꿔 끼운다. 손에 쥔 것 셋을 떠올린다. 이미 뒤집은 앞부분, 지금 노드, 아직 남은 뒷부분이다.

`remove_if` 는 이 모듈에서 빌림 검사기와 가장 많이 다투는 과제다. 같은 `&mut` 참조로 "검사하고, 지우거나 다음으로 넘어가기"를 해야 한다. 하나의 `if let` 안에서 빌린 것을 그대로 덮어쓰려 하면 거절당한다. 검사(`as_ref`)와 변경을 다른 단계로 나누면 풀린다. 맨 앞 노드가 지워질 때와 같은 값이 연달아 올 때를 꼭 따져 본다.

---

## ex04 : btree

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex04/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | `BTree`, `collections`, `.sort` |

이진 탐색 트리를 만든다. 구조는 아래와 똑같이 둔다.

```rust
pub struct TreeNode {
    pub value: i32,
    pub left: Option<Box<TreeNode>>,
    pub right: Option<Box<TreeNode>>,
}

pub struct Tree {
    pub root: Option<Box<TreeNode>>,
}

impl Tree {
    pub fn new() -> Self
    pub fn insert(&mut self, value: i32)
    pub fn contains(&self, value: i32) -> bool
    pub fn inorder(&self) -> Vec<i32>
    pub fn level_count(&self) -> usize
}
```

- `insert` : 노드 값보다 작으면 왼쪽, 같거나 크면 오른쪽으로 내려가 빈자리에 넣는다.
- `inorder` : 왼쪽 → 자신 → 오른쪽 순서로 값을 모은다. 결과는 정렬되어 나온다.
- `level_count` : 층 수. 빈 트리는 0, 뿌리만 있으면 1.

```
insert 50, 30, 70, 20, 40

        50          level_count = 3
       /  \         inorder = [20, 30, 40, 50, 70]
     30    70
    /  \
  20    40
```

`Vec` 은 결과를 담는 데만 쓴다. 정렬은 트리 모양이 대신 해 준다. `.sort` 가 금지인 이유다.

재귀가 자연스럽다. `Option<Box<TreeNode>>` 를 받는 도우미 함수를 하나 두면 빈자리(`None`)가 재귀의 끝이 된다.

---

## ex05 : joint_account

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex05/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

여러 사람이 통장 하나를 같이 쓴다.

```rust
use std::cell::RefCell;
use std::rc::Rc;

pub struct Account {
    pub balance: i64,
}

pub struct Owner {
    pub name: String,
    pub account: Rc<RefCell<Account>>,
}

impl Owner {
    pub fn new(name: &str, account: Rc<RefCell<Account>>) -> Owner
    pub fn deposit(&self, amount: i64)
    pub fn withdraw(&self, amount: i64) -> bool // 잔액이 모자라면 false, 잔액은 그대로
    pub fn balance(&self) -> i64
}

pub fn open_joint(names: &[&str]) -> Vec<Owner> // 잔액 0 인 통장 하나를 모두가 공유
```

```rust
let owners = open_joint(&["kim", "lee"]);
owners[0].deposit(100);
owners[1].balance() // 100
```

왜 `Box` 가 아니라 `Rc` 일까. `Box` 는 주인이 하나다. 두 사람에게 같은 `Box` 를 줄 수 없다. `Rc` 는 "주인이 몇 명인지 세는 상자"다. `Rc::clone` 은 통장을 복사하지 않는다. 주인 수만 1 늘린다. 마지막 주인이 사라질 때 통장도 사라진다.

왜 `RefCell` 까지 필요할까. `deposit` 은 `&self` 만 받는데 잔액을 바꾼다. `Rc` 안의 값은 여럿이 같이 보므로 평소에는 바꿀 수 없다. `RefCell` 은 빌림 규칙 검사를 컴파일 때가 아니라 실행 때 한다. `borrow_mut()` 로 잠깐 빌려서 바꾼다. 같은 순간에 `borrow_mut()` 를 두 번 하면 컴파일은 되지만 실행 중 panic 이 난다.

---

## ex06 : family_tree

| 항목 | 내용 |
|------|------|
| 제출 위치 | `rendu/module07/ex06/` |
| 종류 | 라이브러리 |
| 제출 파일 | `Cargo.toml`, `src/lib.rs` |
| 금지 | 없음 |

부모는 자식을 알고, 자식도 부모를 아는 트리를 만든다.

```rust
use std::cell::RefCell;
use std::rc::{Rc, Weak};

pub struct Node {
    pub name: String,
    pub parent: RefCell<Weak<Node>>,
    pub children: RefCell<Vec<Rc<Node>>>,
}

pub fn new_node(name: &str) -> Rc<Node>             // 부모 없음, 자식 없음
pub fn add_child(parent: &Rc<Node>, child: Rc<Node>) // 양쪽 연결을 모두 만든다
pub fn parent_name(node: &Node) -> Option<String>   // 부모가 없거나 이미 사라졌으면 None
pub fn path(node: &Rc<Node>) -> String              // 뿌리부터 "/" 로 이은 이름
```

```rust
let root = new_node("root");
let usr = new_node("usr");
let bin = new_node("bin");
add_child(&root, Rc::clone(&usr));
add_child(&usr, Rc::clone(&bin));
path(&bin) // "root/usr/bin"
```

부모 → 자식은 `Rc`, 자식 → 부모는 `Weak` 다. 양쪽 다 `Rc` 면 서로가 서로를 붙잡는다. 둘 다 주인 수가 0 이 되지 않아 영영 해제되지 않는다. 이것이 순환 참조로 생기는 메모리 누수다.

`Weak` 는 "보기만 하고 붙잡지는 않는" 참조다. 주인 수에 들어가지 않는다. 그래서 부모가 먼저 사라질 수 있다. 쓸 때는 `upgrade()` 로 아직 살아 있는지 확인한다. 살아 있으면 `Some(Rc)`, 사라졌으면 `None` 이다. 채점은 `Rc::strong_count` 와 `Rc::weak_count` 로 연결 방향을 검사한다.

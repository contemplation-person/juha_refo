use ex01::Stack;

#[test]
fn push_pop_order() {
    let mut s = Stack::new();
    s.push(1);
    s.push(2);
    s.push(3);
    assert_eq!(s.pop(), Some(3));
    assert_eq!(s.pop(), Some(2));
    assert_eq!(s.pop(), Some(1));
    assert_eq!(s.pop(), None);
}

#[test]
fn peek_does_not_remove() {
    let mut s = Stack::new();
    assert_eq!(s.peek(), None);
    s.push("a");
    s.push("b");
    assert_eq!(s.peek(), Some(&"b"));
    assert_eq!(s.len(), 2);
}

#[test]
fn len_and_is_empty() {
    let mut s: Stack<String> = Stack::new();
    assert!(s.is_empty());
    assert_eq!(s.len(), 0);
    s.push(String::from("hi"));
    assert!(!s.is_empty());
    assert_eq!(s.len(), 1);
}

#[test]
fn default_is_empty() {
    let s: Stack<i32> = Stack::default();
    assert!(s.is_empty());
}

#[test]
fn display() {
    let mut s = Stack::new();
    assert_eq!(s.to_string(), "[]");
    s.push(1);
    assert_eq!(s.to_string(), "[1]");
    s.push(2);
    s.push(3);
    assert_eq!(s.to_string(), "[1, 2, 3]");
}

#[test]
fn works_without_display() {
    struct NoDisplay;
    let mut s = Stack::new();
    s.push(NoDisplay);
    assert_eq!(s.len(), 1);
    assert!(s.pop().is_some());
}

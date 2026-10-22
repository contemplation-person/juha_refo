use ex02::{List, Node};

fn values(list: &List) -> Vec<i32> {
    let mut out = Vec::new();
    let mut cur = &list.head;
    while let Some(node) = cur {
        out.push(node.data);
        cur = &node.next;
    }
    out
}

#[test]
fn empty_list() {
    let list = List::new();
    assert!(list.head.is_none());
    assert_eq!(list.size(), 0);
    assert_eq!(list.last(), None);
    assert_eq!(list.at(0), None);
}

#[test]
fn default_is_empty() {
    let list = List::default();
    assert_eq!(list.size(), 0);
}

#[test]
fn push_front_order() {
    let mut list = List::new();
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    assert_eq!(values(&list), [3, 2, 1]);
    assert_eq!(list.size(), 3);
    assert_eq!(list.last(), Some(1));
}

#[test]
fn push_back_order() {
    let mut list = List::new();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert_eq!(values(&list), [1, 2, 3]);
    assert_eq!(list.last(), Some(3));
}

#[test]
fn mixed() {
    let mut list = List::new();
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    list.push_front(0);
    assert_eq!(values(&list), [0, 1, 2, 3]);
}

#[test]
fn at_index() {
    let mut list = List::new();
    for v in [10, 20, 30] {
        list.push_back(v);
    }
    assert_eq!(list.at(0), Some(10));
    assert_eq!(list.at(2), Some(30));
    assert_eq!(list.at(3), None);
    assert_eq!(list.at(1000), None);
}

#[test]
fn built_by_hand() {
    let list = List {
        head: Some(Box::new(Node {
            data: 7,
            next: Some(Box::new(Node { data: 8, next: None })),
        })),
    };
    assert_eq!(list.size(), 2);
    assert_eq!(list.last(), Some(8));
}

#[test]
fn many() {
    let mut list = List::new();
    for i in 0..1000 {
        list.push_back(i);
    }
    assert_eq!(list.size(), 1000);
    assert_eq!(list.at(999), Some(999));
}

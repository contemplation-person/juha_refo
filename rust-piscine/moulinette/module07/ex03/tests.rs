use ex03::List;

fn from(values: &[i32]) -> List {
    let mut list = List::new();
    for v in values.iter().rev() {
        list.push_front(*v);
    }
    list
}

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
fn reverse_basic() {
    let mut list = from(&[1, 2, 3, 4]);
    list.reverse();
    assert_eq!(values(&list), [4, 3, 2, 1]);
}

#[test]
fn reverse_small() {
    let mut empty = List::default();
    empty.reverse();
    assert!(empty.head.is_none());
    let mut one = from(&[42]);
    one.reverse();
    assert_eq!(values(&one), [42]);
}

#[test]
fn reverse_twice() {
    let mut list = from(&[5, 6, 7]);
    list.reverse();
    list.reverse();
    assert_eq!(values(&list), [5, 6, 7]);
}

#[test]
fn remove_middle() {
    let mut list = from(&[1, 2, 3]);
    list.remove_if(2);
    assert_eq!(values(&list), [1, 3]);
}

#[test]
fn remove_head_and_tail() {
    let mut list = from(&[9, 1, 9, 2, 9]);
    list.remove_if(9);
    assert_eq!(values(&list), [1, 2]);
}

#[test]
fn remove_consecutive() {
    let mut list = from(&[1, 4, 4, 4, 2]);
    list.remove_if(4);
    assert_eq!(values(&list), [1, 2]);
}

#[test]
fn remove_everything() {
    let mut list = from(&[3, 3, 3]);
    list.remove_if(3);
    assert!(list.head.is_none());
}

#[test]
fn remove_missing() {
    let mut list = from(&[1, 2]);
    list.remove_if(7);
    assert_eq!(values(&list), [1, 2]);
    let mut empty = List::new();
    empty.remove_if(1);
    assert!(empty.head.is_none());
}

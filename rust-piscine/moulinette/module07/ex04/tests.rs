use ex04::Tree;

fn tree_of(values: &[i32]) -> Tree {
    let mut t = Tree::new();
    for v in values {
        t.insert(*v);
    }
    t
}

#[test]
fn empty_tree() {
    let t = Tree::default();
    assert!(t.root.is_none());
    assert!(t.inorder().is_empty());
    assert_eq!(t.level_count(), 0);
    assert!(!t.contains(1));
}

#[test]
fn shape_follows_rule() {
    let t = tree_of(&[5, 3, 8]);
    let root = t.root.as_ref().unwrap();
    assert_eq!(root.value, 5);
    assert_eq!(root.left.as_ref().unwrap().value, 3);
    assert_eq!(root.right.as_ref().unwrap().value, 8);
}

#[test]
fn duplicates_go_right() {
    let t = tree_of(&[5, 5]);
    let root = t.root.as_ref().unwrap();
    assert!(root.left.is_none());
    assert_eq!(root.right.as_ref().unwrap().value, 5);
}

#[test]
fn inorder_is_sorted() {
    let t = tree_of(&[50, 30, 70, 20, 40, 60, 80, 30]);
    assert_eq!(t.inorder(), [20, 30, 30, 40, 50, 60, 70, 80]);
}

#[test]
fn contains() {
    let t = tree_of(&[50, 30, 70, -5]);
    for v in [50, 30, 70, -5] {
        assert!(t.contains(v));
    }
    for v in [0, 31, 100] {
        assert!(!t.contains(v));
    }
}

#[test]
fn levels() {
    assert_eq!(tree_of(&[1]).level_count(), 1);
    assert_eq!(tree_of(&[2, 1, 3]).level_count(), 2);
    assert_eq!(tree_of(&[1, 2, 3, 4, 5]).level_count(), 5);
    assert_eq!(tree_of(&[50, 30, 70, 20, 40, 60, 80, 10]).level_count(), 4);
}

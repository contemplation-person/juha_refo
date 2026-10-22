use ex06::{add_child, new_node, parent_name, path};
use std::rc::Rc;

#[test]
fn fresh_node() {
    let n = new_node("root");
    assert_eq!(n.name, "root");
    assert_eq!(parent_name(&n), None);
    assert!(n.children.borrow().is_empty());
    assert_eq!(path(&n), "root");
}

#[test]
fn parent_and_children() {
    let root = new_node("root");
    let usr = new_node("usr");
    add_child(&root, Rc::clone(&usr));
    assert_eq!(parent_name(&usr), Some("root".to_string()));
    assert_eq!(root.children.borrow().len(), 1);
    assert_eq!(root.children.borrow()[0].name, "usr");
}

#[test]
fn deep_path() {
    let root = new_node("root");
    let usr = new_node("usr");
    let bin = new_node("bin");
    add_child(&root, Rc::clone(&usr));
    add_child(&usr, Rc::clone(&bin));
    assert_eq!(path(&bin), "root/usr/bin");
    assert_eq!(path(&usr), "root/usr");
}

#[test]
fn parent_link_is_weak() {
    let root = new_node("root");
    let a = new_node("a");
    let b = new_node("b");
    add_child(&root, Rc::clone(&a));
    add_child(&root, Rc::clone(&b));
    assert_eq!(Rc::strong_count(&root), 1);
    assert_eq!(Rc::weak_count(&root), 2);
    assert_eq!(Rc::strong_count(&a), 2);
}

#[test]
fn parent_can_die() {
    let child = new_node("child");
    {
        let root = new_node("root");
        add_child(&root, Rc::clone(&child));
        assert_eq!(parent_name(&child), Some("root".to_string()));
    }
    assert_eq!(parent_name(&child), None);
    assert_eq!(path(&child), "child");
    assert_eq!(Rc::strong_count(&child), 1);
}

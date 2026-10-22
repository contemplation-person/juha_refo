use ex05::{open_joint, Account, Owner};
use std::cell::RefCell;
use std::rc::Rc;

#[test]
fn single_owner() {
    let acc = Rc::new(RefCell::new(Account { balance: 100 }));
    let me = Owner::new("me", acc);
    assert_eq!(me.name, "me");
    assert_eq!(me.balance(), 100);
    me.deposit(50);
    assert_eq!(me.balance(), 150);
}

#[test]
fn shared_between_owners() {
    let acc = Rc::new(RefCell::new(Account { balance: 0 }));
    let a = Owner::new("a", Rc::clone(&acc));
    let b = Owner::new("b", Rc::clone(&acc));
    a.deposit(30);
    assert_eq!(b.balance(), 30);
    assert!(b.withdraw(10));
    assert_eq!(a.balance(), 20);
    assert_eq!(acc.borrow().balance, 20);
}

#[test]
fn withdraw_too_much() {
    let acc = Rc::new(RefCell::new(Account { balance: 10 }));
    let a = Owner::new("a", acc);
    assert!(!a.withdraw(11));
    assert_eq!(a.balance(), 10);
    assert!(a.withdraw(10));
    assert_eq!(a.balance(), 0);
}

#[test]
fn joint_account() {
    let owners = open_joint(&["kim", "lee", "park"]);
    assert_eq!(owners.len(), 3);
    assert_eq!(owners[0].name, "kim");
    assert_eq!(owners[2].name, "park");
    assert_eq!(owners[0].balance(), 0);
    owners[0].deposit(100);
    owners[1].deposit(20);
    assert!(owners[2].withdraw(70));
    for o in &owners {
        assert_eq!(o.balance(), 50);
    }
}

#[test]
fn really_one_account() {
    let owners = open_joint(&["x", "y"]);
    assert!(Rc::ptr_eq(&owners[0].account, &owners[1].account));
    assert_eq!(Rc::strong_count(&owners[0].account), 2);
    drop(owners);
}

#[test]
fn count_drops_with_owner() {
    let acc = Rc::new(RefCell::new(Account { balance: 0 }));
    let a = Owner::new("a", Rc::clone(&acc));
    assert_eq!(Rc::strong_count(&acc), 2);
    drop(a);
    assert_eq!(Rc::strong_count(&acc), 1);
}

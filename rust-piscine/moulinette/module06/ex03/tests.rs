use ex03::{apply_n, compose};

#[test]
fn compose_order() {
    let add1_then_double = compose(|x: i32| x + 1, |x: i32| x * 2);
    assert_eq!(add1_then_double(3), 8);
    let double_then_add1 = compose(|x: i32| x * 2, |x: i32| x + 1);
    assert_eq!(double_then_add1(3), 7);
}

#[test]
fn compose_changes_types() {
    let len_is_even = compose(|s: &str| s.len(), |n: usize| n % 2 == 0);
    assert!(len_is_even("ab"));
    assert!(!len_is_even("abc"));
}

#[test]
fn compose_captures() {
    let prefix = String::from(">> ");
    let shout = compose(
        |s: &str| s.to_uppercase(),
        move |s: String| format!("{prefix}{s}"),
    );
    assert_eq!(shout("hi"), ">> HI");
    assert_eq!(shout("rust"), ">> RUST");
}

#[test]
fn compose_nested() {
    let f = compose(compose(|x: i32| x + 1, |x: i32| x * 10), |x: i32| x - 3);
    assert_eq!(f(1), 17);
}

#[test]
fn apply_n_numbers() {
    assert_eq!(apply_n(|x| x * 2, 10, 1), 1024);
    assert_eq!(apply_n(|x: i32| x + 1, 0, 42), 42);
}

#[test]
fn apply_n_owned() {
    let s = apply_n(
        |mut s: String| {
            s.push('!');
            s
        },
        3,
        String::from("hey"),
    );
    assert_eq!(s, "hey!!!");
}

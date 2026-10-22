use ex01::{ft_any, ft_count_if, ft_is_sort};

#[test]
fn any() {
    assert!(ft_any(&[1, 3, 4, 7], |x| x % 2 == 0));
    assert!(!ft_any(&[1, 3, 5], |x| x % 2 == 0));
    let empty: [i32; 0] = [];
    assert!(!ft_any(&empty, |_| true));
}

#[test]
fn any_stops_early() {
    let mut calls = 0;
    let found = ft_any(&[1, 2, 3, 4, 5], |x| {
        calls += 1;
        *x == 2
    });
    assert!(found);
    assert_eq!(calls, 2);
}

#[test]
fn count_if() {
    assert_eq!(ft_count_if(&["", "a", "", "bc"], |s| s.is_empty()), 2);
    assert_eq!(ft_count_if(&[1, 2, 3, 4, 5, 6], |x| *x > 3), 3);
    let empty: [u8; 0] = [];
    assert_eq!(ft_count_if(&empty, |_| true), 0);
}

#[test]
fn is_sort_ascending_and_descending() {
    assert!(ft_is_sort(&[1, 2, 2, 5], |a, b| a.cmp(b)));
    assert!(ft_is_sort(&[9, 4, 4, 0], |a, b| a.cmp(b)));
    assert!(!ft_is_sort(&[1, 3, 2], |a, b| a.cmp(b)));
}

#[test]
fn is_sort_trivial() {
    let empty: [i32; 0] = [];
    assert!(ft_is_sort(&empty, |a, b| a.cmp(b)));
    assert!(ft_is_sort(&[7], |a, b| a.cmp(b)));
    assert!(ft_is_sort(&[3, 3, 3], |a, b| a.cmp(b)));
}

#[test]
fn is_sort_custom_order() {
    let words = ["a", "bb", "ccc", "zzzz"];
    assert!(ft_is_sort(&words, |a, b| a.len().cmp(&b.len())));
    let words = ["zz", "a", "bbb"];
    assert!(!ft_is_sort(&words, |a, b| a.len().cmp(&b.len())));
}

use ex03::{add_options, find_index, safe_div};

#[test]
fn div_ok() {
    assert_eq!(safe_div(10, 2), Some(5));
    assert_eq!(safe_div(7, 2), Some(3));
    assert_eq!(safe_div(-7, 2), Some(-3));
    assert_eq!(safe_div(0, 5), Some(0));
}

#[test]
fn div_by_zero() {
    assert_eq!(safe_div(1, 0), None);
    assert_eq!(safe_div(0, 0), None);
}

#[test]
fn div_overflow() {
    assert_eq!(safe_div(i32::MIN, -1), None);
    assert_eq!(safe_div(i32::MIN, 1), Some(i32::MIN));
    assert_eq!(safe_div(i32::MAX, -1), Some(-i32::MAX));
}

#[test]
fn find_first() {
    assert_eq!(find_index(&[4, 8, 15, 16, 23, 42], 15), Some(2));
    assert_eq!(find_index(&[4, 8, 15, 16, 23, 42], 4), Some(0));
    assert_eq!(find_index(&[4, 8, 15, 16, 23, 42], 42), Some(5));
}

#[test]
fn find_duplicates_returns_first() {
    assert_eq!(find_index(&[1, 2, 1, 2], 2), Some(1));
}

#[test]
fn find_missing() {
    assert_eq!(find_index(&[1, 2, 3], 9), None);
    assert_eq!(find_index(&[], 0), None);
}

#[test]
fn add_both_some() {
    assert_eq!(add_options(Some(2), Some(40)), Some(42));
    assert_eq!(add_options(Some(-5), Some(5)), Some(0));
}

#[test]
fn add_with_none() {
    assert_eq!(add_options(None, Some(1)), None);
    assert_eq!(add_options(Some(1), None), None);
    assert_eq!(add_options(None, None), None);
}

use ex04::{median, mode};

#[test]
fn median_odd() {
    assert_eq!(median(&[3, 1, 2]), Some(2.0));
    assert_eq!(median(&[7]), Some(7.0));
}

#[test]
fn median_even() {
    assert_eq!(median(&[4, 1, 3, 2]), Some(2.5));
    assert_eq!(median(&[-1, 1]), Some(0.0));
}

#[test]
fn median_empty() {
    assert_eq!(median(&[]), None);
}

#[test]
fn median_does_not_overflow() {
    assert_eq!(median(&[i32::MAX, i32::MAX]), Some(2_147_483_647.0));
    assert_eq!(median(&[i32::MIN, i32::MAX]), Some(-0.5));
}

#[test]
fn median_keeps_input() {
    let v = vec![3, 1, 2];
    median(&v);
    assert_eq!(v, vec![3, 1, 2]);
}

#[test]
fn mode_basic() {
    assert_eq!(mode(&[1, 2, 2, 3]), Some(2));
    assert_eq!(mode(&[5]), Some(5));
    assert_eq!(mode(&[-1, -1, 7, 7, 7]), Some(7));
}

#[test]
fn mode_tie_takes_smallest() {
    assert_eq!(mode(&[3, 1, 3, 1]), Some(1));
    assert_eq!(mode(&[9, 8, 7]), Some(7));
}

#[test]
fn mode_empty() {
    assert_eq!(mode(&[]), None);
}

use ex02::sum_csv;
use std::num::IntErrorKind;

fn kind(s: &str) -> IntErrorKind {
    sum_csv(s).unwrap_err().kind().clone()
}

#[test]
fn sums() {
    assert_eq!(sum_csv("1,2,3"), Ok(6));
    assert_eq!(sum_csv("42"), Ok(42));
    assert_eq!(sum_csv(" 10 , -4 ,5 "), Ok(11));
}

#[test]
fn bad_number() {
    assert_eq!(kind("1,x,3"), IntErrorKind::InvalidDigit);
    assert_eq!(kind("1,2 3"), IntErrorKind::InvalidDigit);
}

#[test]
fn empty_items() {
    assert_eq!(kind(""), IntErrorKind::Empty);
    assert_eq!(kind("1,,2"), IntErrorKind::Empty);
    assert_eq!(kind("1,2,"), IntErrorKind::Empty);
}

#[test]
fn first_error_wins() {
    assert_eq!(kind("x,,"), IntErrorKind::InvalidDigit);
    assert_eq!(kind(",x"), IntErrorKind::Empty);
}

#[test]
fn too_big() {
    assert_eq!(kind("1,99999999999999999999"), IntErrorKind::PosOverflow);
}

#[test]
fn error_is_parse_int_error() {
    let e: std::num::ParseIntError = sum_csv("a").unwrap_err();
    assert_eq!(e, "a".parse::<i64>().unwrap_err());
}

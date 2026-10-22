use ex04::{AtoiError, ft_atoi};
use std::error::Error;

#[test]
fn valid() {
    assert_eq!(ft_atoi("0"), Ok(0));
    assert_eq!(ft_atoi("42"), Ok(42));
    assert_eq!(ft_atoi("+42"), Ok(42));
    assert_eq!(ft_atoi("-42"), Ok(-42));
    assert_eq!(ft_atoi("007"), Ok(7));
    assert_eq!(ft_atoi("-0"), Ok(0));
}

#[test]
fn limits() {
    assert_eq!(ft_atoi("2147483647"), Ok(i32::MAX));
    assert_eq!(ft_atoi("-2147483648"), Ok(i32::MIN));
    assert_eq!(ft_atoi("0000000000002147483647"), Ok(i32::MAX));
}

#[test]
fn overflow() {
    assert_eq!(ft_atoi("2147483648"), Err(AtoiError::Overflow));
    assert_eq!(ft_atoi("-2147483649"), Err(AtoiError::Overflow));
    assert_eq!(ft_atoi("99999999999999999999999"), Err(AtoiError::Overflow));
}

#[test]
fn empty() {
    assert_eq!(ft_atoi(""), Err(AtoiError::Empty));
}

#[test]
fn invalid_digit() {
    for s in ["-", "+", " 42", "42 ", "4 2", "--1", "+-1", "12a", "a", "٣"] {
        assert_eq!(ft_atoi(s), Err(AtoiError::InvalidDigit), "input {s:?}");
    }
}

#[test]
fn characters_are_checked_before_overflow() {
    assert_eq!(ft_atoi("99999999999999999999a"), Err(AtoiError::InvalidDigit));
}

#[test]
fn display() {
    assert_eq!(AtoiError::Empty.to_string(), "empty string");
    assert_eq!(AtoiError::InvalidDigit.to_string(), "invalid digit found");
    assert_eq!(AtoiError::Overflow.to_string(), "number out of range for i32");
}

#[test]
fn is_std_error() {
    let e: Box<dyn Error> = Box::new(AtoiError::Overflow);
    assert_eq!(e.to_string(), "number out of range for i32");
}

use ex01::{PasswordError, check_password};
use std::error::Error;

#[test]
fn good() {
    assert_eq!(check_password("Longpassword1"), Ok(()));
    assert_eq!(check_password("A1bcdefg"), Ok(()));
}

#[test]
fn too_short() {
    assert_eq!(check_password(""), Err(PasswordError::TooShort));
    assert_eq!(check_password("Short1A"), Err(PasswordError::TooShort));
}

#[test]
fn length_counts_characters_not_bytes() {
    // 한글 한 글자는 3바이트지만 글자 수는 1이다.
    assert_eq!(check_password("A1한글"), Err(PasswordError::TooShort));
    assert_eq!(check_password("A1한글한글한글"), Ok(()));
}

#[test]
fn no_digit() {
    assert_eq!(check_password("Longpassword"), Err(PasswordError::NoDigit));
    // 숫자 검사가 대문자 검사보다 먼저다.
    assert_eq!(check_password("longpassword"), Err(PasswordError::NoDigit));
}

#[test]
fn no_uppercase() {
    assert_eq!(check_password("longpassword1"), Err(PasswordError::NoUppercase));
    assert_eq!(check_password("가나다라마바사1"), Err(PasswordError::NoUppercase));
    assert_eq!(check_password("Écolepass1"), Err(PasswordError::NoUppercase));
}

#[test]
fn display() {
    assert_eq!(
        PasswordError::TooShort.to_string(),
        "password must be at least 8 characters"
    );
    assert_eq!(
        PasswordError::NoDigit.to_string(),
        "password must contain a digit"
    );
    assert_eq!(
        PasswordError::NoUppercase.to_string(),
        "password must contain an uppercase letter"
    );
}

#[test]
fn is_std_error() {
    let e: Box<dyn Error> = Box::new(PasswordError::NoDigit);
    assert_eq!(e.to_string(), "password must contain a digit");
}

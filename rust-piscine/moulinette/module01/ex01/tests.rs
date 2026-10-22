use ex01::ft_strlen;

#[test]
fn empty() {
    assert_eq!(ft_strlen(""), 0);
}

#[test]
fn ascii() {
    assert_eq!(ft_strlen("a"), 1);
    assert_eq!(ft_strlen("hello"), 5);
    assert_eq!(ft_strlen("Rust Piscine 42"), 15);
}

#[test]
fn korean_counts_letters_not_bytes() {
    assert_eq!(ft_strlen("한글"), 2);
    assert_eq!(ft_strlen("러스트 피신"), 6);
}

#[test]
fn mixed() {
    assert_eq!(ft_strlen("café"), 4);
    assert_eq!(ft_strlen("abc한글🦀"), 6);
}

#[test]
fn works_on_string_too() {
    let s = String::from("borrow me");
    assert_eq!(ft_strlen(&s), 9);
    assert_eq!(s, "borrow me");
}

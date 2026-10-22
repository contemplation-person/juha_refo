use ex03::ft_strrev;

fn rev(s: &str) -> String {
    let mut owned = String::from(s);
    ft_strrev(&mut owned);
    owned
}

#[test]
fn basic() {
    assert_eq!(rev("hello"), "olleh");
    assert_eq!(rev("ab"), "ba");
}

#[test]
fn empty_and_single() {
    assert_eq!(rev(""), "");
    assert_eq!(rev("a"), "a");
}

#[test]
fn palindrome() {
    assert_eq!(rev("racecar"), "racecar");
}

#[test]
fn korean_and_emoji() {
    assert_eq!(rev("한글abc"), "cba글한");
    assert_eq!(rev("🦀 rust"), "tsur 🦀");
}

#[test]
fn twice_is_identity() {
    let mut s = String::from("Rust Piscine 42");
    ft_strrev(&mut s);
    ft_strrev(&mut s);
    assert_eq!(s, "Rust Piscine 42");
}

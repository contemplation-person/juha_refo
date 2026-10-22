use ex03::word_count;

#[test]
fn counts_case_insensitive() {
    let m = word_count("Hello, hello! HELLO world.");
    assert_eq!(m.get("hello"), Some(&3));
    assert_eq!(m.get("world"), Some(&1));
    assert_eq!(m.len(), 2);
}

#[test]
fn empty_and_punctuation_only() {
    assert!(word_count("").is_empty());
    assert!(word_count("  ...  !!! ").is_empty());
}

#[test]
fn apostrophe_splits() {
    let m = word_count("don't");
    assert_eq!(m.get("don"), Some(&1));
    assert_eq!(m.get("t"), Some(&1));
    assert_eq!(m.len(), 2);
}

#[test]
fn digits_are_words() {
    let m = word_count("42 is 42");
    assert_eq!(m.get("42"), Some(&2));
    assert_eq!(m.get("is"), Some(&1));
    assert_eq!(m.len(), 2);
}

#[test]
fn unicode() {
    let m = word_count("Rust 러스트, 러스트! ÉCOLE école");
    assert_eq!(m.get("rust"), Some(&1));
    assert_eq!(m.get("러스트"), Some(&2));
    assert_eq!(m.get("école"), Some(&2));
    assert_eq!(m.len(), 3);
}

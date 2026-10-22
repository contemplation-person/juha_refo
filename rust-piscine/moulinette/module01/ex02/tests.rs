use ex02::first_word;

#[test]
fn two_words() {
    assert_eq!(first_word("hello world"), "hello");
}

#[test]
fn single_word() {
    assert_eq!(first_word("hello"), "hello");
}

#[test]
fn empty() {
    assert_eq!(first_word(""), "");
}

#[test]
fn leading_space() {
    assert_eq!(first_word(" hello"), "");
}

#[test]
fn many_spaces() {
    assert_eq!(first_word("a  b   c"), "a");
}

#[test]
fn korean() {
    assert_eq!(first_word("한글 단어"), "한글");
    assert_eq!(first_word("러스트"), "러스트");
}

#[test]
fn returns_a_view_into_the_original() {
    let s = String::from("borrowed slice");
    let w = first_word(&s);
    assert_eq!(w, "borrowed");
    assert!(std::ptr::eq(w.as_ptr(), s.as_ptr()));
}

use ex05::ft_strjoin;

#[test]
fn basic() {
    assert_eq!(ft_strjoin(&["a", "b", "c"], ", "), "a, b, c");
}

#[test]
fn empty_list() {
    assert_eq!(ft_strjoin(&[], ", "), "");
}

#[test]
fn single() {
    assert_eq!(ft_strjoin(&["only"], " -- "), "only");
}

#[test]
fn empty_parts() {
    assert_eq!(ft_strjoin(&["", ""], "-"), "-");
    assert_eq!(ft_strjoin(&["", "a", ""], "/"), "/a/");
}

#[test]
fn empty_separator() {
    assert_eq!(ft_strjoin(&["ab", "cd", "ef"], ""), "abcdef");
}

#[test]
fn korean() {
    assert_eq!(ft_strjoin(&["러스트", "피신"], " · "), "러스트 · 피신");
}

#[test]
fn borrows_from_strings() {
    let owned = [String::from("x"), String::from("y")];
    let parts: Vec<&str> = owned.iter().map(|s| s.as_str()).collect();
    assert_eq!(ft_strjoin(&parts, "+"), "x+y");
    assert_eq!(owned[0], "x");
}

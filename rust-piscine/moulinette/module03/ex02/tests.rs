use ex02::ft_split;

fn s(v: &[&str]) -> Vec<String> {
    v.iter().map(|x| x.to_string()).collect()
}

#[test]
fn spaces() {
    assert_eq!(ft_split("hello world", " "), s(&["hello", "world"]));
}

#[test]
fn skips_empty_pieces() {
    assert_eq!(ft_split("  a  b ", " "), s(&["a", "b"]));
    assert_eq!(ft_split(",,,", ","), s(&[]));
    assert_eq!(ft_split("", " "), s(&[]));
}

#[test]
fn several_separators() {
    assert_eq!(ft_split("a,b;;c", ",;"), s(&["a", "b", "c"]));
    assert_eq!(ft_split("1 + 2 - 3", "+- "), s(&["1", "2", "3"]));
}

#[test]
fn no_separator_found() {
    assert_eq!(ft_split("abc", ""), s(&["abc"]));
    assert_eq!(ft_split("abc", "xyz"), s(&["abc"]));
}

#[test]
fn unicode() {
    assert_eq!(ft_split("사과,배;포도", ",;"), s(&["사과", "배", "포도"]));
    assert_eq!(ft_split("a한b한한c", "한"), s(&["a", "b", "c"]));
}

#[test]
fn newlines() {
    assert_eq!(ft_split("one\ntwo\n\nthree\n", "\n"), s(&["one", "two", "three"]));
}

use ex00::longest;

#[test]
fn second_is_longer() {
    assert_eq!(longest("ab", "abcd"), "abcd");
}

#[test]
fn first_is_longer() {
    assert_eq!(longest("piscine", "rust"), "piscine");
}

#[test]
fn tie_returns_first() {
    assert_eq!(longest("left", "righ"), "left");
    assert_eq!(longest("", ""), "");
}

#[test]
fn returns_the_same_slice() {
    let a = String::from("short");
    let b = String::from("much longer");
    let r = longest(&a, &b);
    assert!(std::ptr::eq(r, b.as_str()));
}

#[test]
fn works_with_different_scopes() {
    let outer = String::from("outer string");
    let result;
    {
        let inner = String::from("in");
        result = longest(&outer, &inner).to_string();
    }
    assert_eq!(result, "outer string");
}

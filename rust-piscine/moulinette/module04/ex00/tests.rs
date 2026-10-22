use ex00::parse_age;

fn err(s: &str) -> Result<u8, String> {
    Err(s.to_string())
}

#[test]
fn valid() {
    assert_eq!(parse_age("42"), Ok(42));
    assert_eq!(parse_age("0"), Ok(0));
    assert_eq!(parse_age("150"), Ok(150));
}

#[test]
fn trims_whitespace() {
    assert_eq!(parse_age(" 7 \n"), Ok(7));
}

#[test]
fn empty() {
    assert_eq!(parse_age(""), err("empty"));
    assert_eq!(parse_age("  \t "), err("empty"));
}

#[test]
fn not_a_number() {
    assert_eq!(parse_age("abc"), err("not a number"));
    assert_eq!(parse_age("-5"), err("not a number"));
    assert_eq!(parse_age("4 2"), err("not a number"));
    assert_eq!(parse_age("12.5"), err("not a number"));
}

#[test]
fn too_old() {
    assert_eq!(parse_age("151"), err("too old"));
    assert_eq!(parse_age("1000"), err("too old"));
}

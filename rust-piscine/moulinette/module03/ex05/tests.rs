use ex05::ft_convert_base;

const DEC: &str = "0123456789";
const HEX: &str = "0123456789abcdef";

fn conv(n: &str, from: &str, to: &str) -> Option<String> {
    ft_convert_base(n, from, to)
}

fn some(s: &str) -> Option<String> {
    Some(s.to_string())
}

#[test]
fn basic() {
    assert_eq!(conv("42", DEC, "01"), some("101010"));
    assert_eq!(conv("ff", HEX, DEC), some("255"));
    assert_eq!(conv("255", DEC, HEX), some("ff"));
    assert_eq!(conv("7", DEC, DEC), some("7"));
}

#[test]
fn custom_base() {
    // p=0 o=1 n=2 e=3 y=4 v=5 i=6 f=7
    assert_eq!(conv("poneyvif", "poneyvif", DEC), some("342391"));
    assert_eq!(conv("10", DEC, "poneyvif"), some("on"));
}

#[test]
fn unicode_base() {
    assert_eq!(conv("5", DEC, "가나다"), some("나다"));
    assert_eq!(conv("나다", "가나다", DEC), some("5"));
}

#[test]
fn whitespace_and_signs() {
    assert_eq!(conv("  --+-2a", HEX, DEC), some("-42"));
    assert_eq!(conv("\t\n -+-42", DEC, DEC), some("42"));
}

#[test]
fn zero() {
    assert_eq!(conv("0", DEC, "01"), some("0"));
    assert_eq!(conv("-0", DEC, DEC), some("0"));
    assert_eq!(conv("", DEC, DEC), some("0"));
    assert_eq!(conv("xyz", DEC, "ab"), some("a"));
}

#[test]
fn stops_at_first_non_base_char() {
    assert_eq!(conv("12abc34", DEC, DEC), some("12"));
    assert_eq!(conv("12 34", DEC, DEC), some("12"));
}

#[test]
fn invalid_bases() {
    assert_eq!(conv("1", "", DEC), None);
    assert_eq!(conv("1", "0", DEC), None);
    assert_eq!(conv("1", "0120", DEC), None);
    assert_eq!(conv("1", "01+", DEC), None);
    assert_eq!(conv("1", "01-", DEC), None);
    assert_eq!(conv("1", "0 1", DEC), None);
    assert_eq!(conv("1", DEC, "0\t1"), None);
    assert_eq!(conv("1", DEC, "aa"), None);
}

#[test]
fn big_numbers() {
    assert_eq!(conv("9223372036854775807", DEC, HEX), some("7fffffffffffffff"));
    assert_eq!(conv("-9223372036854775807", DEC, DEC), some("-9223372036854775807"));
    assert_eq!(conv("-7fffffffffffffff", HEX, "01"), some(&format!("-{}", "1".repeat(63))));
}

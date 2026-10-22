use ex06::{Config, ConfigError, parse_config};
use std::error::Error;
use std::num::ParseIntError;

fn pie(s: &str) -> ParseIntError {
    s.parse::<u32>().unwrap_err()
}

#[test]
fn simple() {
    assert_eq!(
        parse_config("width=80\nheight=24"),
        Ok(Config {
            width: 80,
            height: 24
        })
    );
}

#[test]
fn comments_blanks_spaces_and_last_wins() {
    let text = "# window\n\n  width = 100 \n\t# size\nheight=50\nwidth=120\n";
    assert_eq!(
        parse_config(text),
        Ok(Config {
            width: 120,
            height: 50
        })
    );
}

#[test]
fn bad_line() {
    assert_eq!(parse_config("width=80\nheight"), Err(ConfigError::BadLine(2)));
    assert_eq!(parse_config("\n\noops\n"), Err(ConfigError::BadLine(3)));
}

#[test]
fn unknown_key() {
    assert_eq!(
        parse_config("width=80\ncolor=red"),
        Err(ConfigError::UnknownKey("color".to_string()))
    );
    assert_eq!(
        parse_config("=5"),
        Err(ConfigError::UnknownKey(String::new()))
    );
}

#[test]
fn bad_number() {
    assert_eq!(
        parse_config("width=abc"),
        Err(ConfigError::BadNumber(pie("abc")))
    );
    assert_eq!(
        parse_config("height=24\nwidth=-1"),
        Err(ConfigError::BadNumber(pie("-1")))
    );
    assert_eq!(parse_config("width="), Err(ConfigError::BadNumber(pie(""))));
}

#[test]
fn missing_key() {
    let missing = |k: &str| Err(ConfigError::MissingKey(k.to_string()));
    assert_eq!(parse_config(""), missing("width"));
    assert_eq!(parse_config("height=24"), missing("width"));
    assert_eq!(parse_config("width=1"), missing("height"));
}

#[test]
fn first_error_wins() {
    assert_eq!(
        parse_config("color=red\nwidth=x\nnope"),
        Err(ConfigError::UnknownKey("color".to_string()))
    );
}

#[test]
fn from_parse_int_error() {
    let e: ConfigError = pie("x").into();
    assert_eq!(e, ConfigError::BadNumber(pie("x")));
}

#[test]
fn display() {
    assert_eq!(
        ConfigError::BadLine(3).to_string(),
        "line 3: expected key=value"
    );
    assert_eq!(
        ConfigError::UnknownKey("color".to_string()).to_string(),
        "unknown key: color"
    );
    assert_eq!(
        ConfigError::BadNumber(pie("x")).to_string(),
        "bad number: invalid digit found in string"
    );
    assert_eq!(
        ConfigError::MissingKey("height".to_string()).to_string(),
        "missing key: height"
    );
}

#[test]
fn source() {
    let e = ConfigError::BadNumber(pie("x"));
    let inner = e.source().expect("BadNumber must have a source");
    assert_eq!(inner.to_string(), "invalid digit found in string");
    assert!(ConfigError::BadLine(1).source().is_none());
    assert!(ConfigError::UnknownKey("a".to_string()).source().is_none());
    assert!(ConfigError::MissingKey("width".to_string()).source().is_none());
}

use ex04::ft_strcapitalize;

#[test]
fn classic_42() {
    assert_eq!(
        ft_strcapitalize("salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un"),
        "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"
    );
}

#[test]
fn lowers_the_rest() {
    assert_eq!(ft_strcapitalize("HELLO wORLD"), "Hello World");
}

#[test]
fn empty_and_single() {
    assert_eq!(ft_strcapitalize(""), "");
    assert_eq!(ft_strcapitalize("a"), "A");
    assert_eq!(ft_strcapitalize("Z"), "Z");
}

#[test]
fn digits_start_a_word() {
    assert_eq!(ft_strcapitalize("42SEOUL is cool"), "42seoul Is Cool");
}

#[test]
fn separators() {
    assert_eq!(ft_strcapitalize("a.b_c d\te"), "A.B_C D\tE");
}

#[test]
fn non_ascii_is_a_separator() {
    assert_eq!(ft_strcapitalize("한글abc DEF"), "한글Abc Def");
}

#[test]
fn input_is_untouched() {
    let s = String::from("keep me");
    let out = ft_strcapitalize(&s);
    assert_eq!(s, "keep me");
    assert_eq!(out, "Keep Me");
}

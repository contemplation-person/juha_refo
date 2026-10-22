use ex01::Words;

fn all(text: &str) -> Vec<&str> {
    let mut w = Words::new(text);
    let mut out = Vec::new();
    while let Some(word) = w.next_word() {
        out.push(word);
    }
    out
}

#[test]
fn simple() {
    assert_eq!(all("hello rust piscine"), ["hello", "rust", "piscine"]);
}

#[test]
fn messy_spaces() {
    assert_eq!(all("  \t one   two\nthree  \n"), ["one", "two", "three"]);
}

#[test]
fn empty_and_blank() {
    assert!(all("").is_empty());
    assert!(all("   \n\t ").is_empty());
}

#[test]
fn keeps_returning_none() {
    let mut w = Words::new("solo");
    assert_eq!(w.next_word(), Some("solo"));
    assert_eq!(w.next_word(), None);
    assert_eq!(w.next_word(), None);
}

#[test]
fn unicode_words() {
    assert_eq!(all("러스트 피신 42"), ["러스트", "피신", "42"]);
}

#[test]
fn words_point_into_original_text() {
    let text = String::from("aa bb cc");
    let start = text.as_ptr() as usize;
    let end = start + text.len();
    for word in all(&text) {
        let p = word.as_ptr() as usize;
        assert!(p >= start && p + word.len() <= end, "word is not a slice of the input");
    }
}

#[test]
fn word_outlives_the_tokenizer() {
    let text = String::from("first second");
    let word;
    {
        let mut w = Words::new(&text);
        word = w.next_word().unwrap();
    }
    assert_eq!(word, "first");
}

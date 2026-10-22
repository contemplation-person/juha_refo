use ex04::{count_vowels, longest_word, sum_of_odd_squares, word_lengths};

#[test]
fn odd_squares() {
    assert_eq!(sum_of_odd_squares(&[1, 2, 3, 4, 5]), 35);
    assert_eq!(sum_of_odd_squares(&[-3, 2, 4]), 9);
    assert_eq!(sum_of_odd_squares(&[2, 4, 6]), 0);
    assert_eq!(sum_of_odd_squares(&[]), 0);
}

#[test]
fn lengths() {
    assert_eq!(word_lengths("the quick  brown\tfox"), [3, 5, 5, 3]);
    assert_eq!(word_lengths("   "), Vec::<usize>::new());
    assert_eq!(word_lengths("러스트 좋다"), [3, 2]);
}

#[test]
fn longest() {
    assert_eq!(longest_word("a bbb cc"), Some("bbb"));
    assert_eq!(longest_word(""), None);
    assert_eq!(longest_word("  \n "), None);
}

#[test]
fn longest_tie_keeps_first() {
    assert_eq!(longest_word("one two six"), Some("one"));
    assert_eq!(longest_word("hi abc xyz de"), Some("abc"));
}

#[test]
fn longest_counts_chars_not_bytes() {
    assert_eq!(longest_word("가나다 abcd"), Some("abcd"));
}

#[test]
fn vowels() {
    assert_eq!(count_vowels("Hello, World"), 3);
    assert_eq!(count_vowels("AEIOU aeiou"), 10);
    assert_eq!(count_vowels("rhythm"), 0);
}

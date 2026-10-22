use ex05::{group_runs, rle_decode, rle_encode};

#[test]
fn runs_numbers() {
    assert_eq!(
        group_runs(&[1, 1, 2, 3, 3, 3, 1]),
        [(1, 2), (2, 1), (3, 3), (1, 1)]
    );
}

#[test]
fn runs_empty_and_single() {
    let empty: [i32; 0] = [];
    assert_eq!(group_runs(&empty), []);
    assert_eq!(group_runs(&["x"]), [("x", 1)]);
}

#[test]
fn runs_strings() {
    let v = [String::from("a"), String::from("a"), String::from("b")];
    assert_eq!(
        group_runs(&v),
        [(String::from("a"), 2), (String::from("b"), 1)]
    );
}

#[test]
fn encode() {
    assert_eq!(rle_encode("aaabccdddd"), "a3b1c2d4");
    assert_eq!(rle_encode(""), "");
    assert_eq!(rle_encode("가가나"), "가2나1");
    assert_eq!(rle_encode("zzzzzzzzzzzz"), "z12");
}

#[test]
fn decode() {
    assert_eq!(rle_decode("a3b1c2d4"), "aaabccdddd");
    assert_eq!(rle_decode(""), "");
    assert_eq!(rle_decode("z12"), "zzzzzzzzzzzz");
    assert_eq!(rle_decode("가2나1"), "가가나");
}

#[test]
fn roundtrip() {
    for s in ["hello", "  x  ", "mississippi", "ㅋㅋㅋㅋ"] {
        assert_eq!(rle_decode(&rle_encode(s)), s);
    }
}

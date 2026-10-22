use ex00::largest;

#[test]
fn integers() {
    assert_eq!(largest(&[34, 50, 25, 100, 65]), Some(100));
    assert_eq!(largest(&[-3, -1, -7]), Some(-1));
}

#[test]
fn floats() {
    assert_eq!(largest(&[1.5, -2.0, 3.25, 0.0]), Some(3.25));
}

#[test]
fn chars() {
    assert_eq!(largest(&['y', 'm', 'a', 'q']), Some('y'));
}

#[test]
fn single() {
    assert_eq!(largest(&[42u8]), Some(42));
}

#[test]
fn empty() {
    let empty: [i32; 0] = [];
    assert_eq!(largest(&empty), None);
}

#[test]
fn first_and_last() {
    assert_eq!(largest(&[9, 1, 2]), Some(9));
    assert_eq!(largest(&[1, 2, 9]), Some(9));
}

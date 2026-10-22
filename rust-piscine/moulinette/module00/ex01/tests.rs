use ex01::max_of_three;

#[test]
fn first_is_biggest() {
    assert_eq!(max_of_three(3, 1, 2), 3);
}

#[test]
fn second_is_biggest() {
    assert_eq!(max_of_three(1, 3, 2), 3);
}

#[test]
fn third_is_biggest() {
    assert_eq!(max_of_three(1, 2, 3), 3);
}

#[test]
fn negatives() {
    assert_eq!(max_of_three(-7, -3, -5), -3);
}

#[test]
fn ties() {
    assert_eq!(max_of_three(4, 4, 4), 4);
    assert_eq!(max_of_three(5, 5, 1), 5);
    assert_eq!(max_of_three(1, 5, 5), 5);
}

#[test]
fn extremes() {
    assert_eq!(max_of_three(i32::MIN, i32::MAX, 0), i32::MAX);
    assert_eq!(max_of_three(i32::MIN, i32::MIN, i32::MIN), i32::MIN);
}

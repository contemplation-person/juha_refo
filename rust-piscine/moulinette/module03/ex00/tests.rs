use ex00::ft_range;

#[test]
fn basic() {
    assert_eq!(ft_range(0, 5), vec![0, 1, 2, 3, 4]);
}

#[test]
fn negative() {
    assert_eq!(ft_range(-3, 2), vec![-3, -2, -1, 0, 1]);
}

#[test]
fn empty_when_equal() {
    assert!(ft_range(4, 4).is_empty());
}

#[test]
fn empty_when_reversed() {
    assert!(ft_range(10, -10).is_empty());
    assert!(ft_range(i32::MAX, i32::MIN).is_empty());
}

#[test]
fn extremes() {
    assert_eq!(ft_range(i32::MAX - 2, i32::MAX), vec![i32::MAX - 2, i32::MAX - 1]);
    assert_eq!(
        ft_range(i32::MIN, i32::MIN + 3),
        vec![i32::MIN, i32::MIN + 1, i32::MIN + 2]
    );
}

#[test]
fn large() {
    let v = ft_range(-500_000, 500_000);
    assert_eq!(v.len(), 1_000_000);
    assert_eq!(v[0], -500_000);
    assert_eq!(v[999_999], 499_999);
}

use ex00::ft_div_mod;

fn run(a: i32, b: i32) -> (i32, i32) {
    let mut div = 0;
    let mut rem = 0;
    ft_div_mod(a, b, &mut div, &mut rem);
    (div, rem)
}

#[test]
fn basic() {
    assert_eq!(run(7, 2), (3, 1));
    assert_eq!(run(42, 6), (7, 0));
}

#[test]
fn smaller_than_divisor() {
    assert_eq!(run(3, 10), (0, 3));
    assert_eq!(run(0, 5), (0, 0));
}

#[test]
fn negatives_truncate_toward_zero() {
    assert_eq!(run(-7, 2), (-3, -1));
    assert_eq!(run(7, -2), (-3, 1));
    assert_eq!(run(-7, -2), (3, -1));
}

#[test]
fn overwrites_old_values() {
    let mut div = 999;
    let mut rem = -999;
    ft_div_mod(10, 3, &mut div, &mut rem);
    assert_eq!((div, rem), (3, 1));
}

#[test]
fn extremes() {
    assert_eq!(run(i32::MAX, 1), (i32::MAX, 0));
    assert_eq!(run(i32::MIN, 2), (i32::MIN / 2, 0));
}

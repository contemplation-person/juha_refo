use ex01::ft_sort_int_tab;

fn check(mut v: Vec<i32>) {
    let mut want = v.clone();
    want.sort();
    ft_sort_int_tab(&mut v);
    assert_eq!(v, want);
}

#[test]
fn basic() {
    check(vec![5, 2, 9, 1, 3]);
}

#[test]
fn empty_and_single() {
    check(vec![]);
    check(vec![42]);
}

#[test]
fn already_sorted_and_reversed() {
    check(vec![1, 2, 3, 4, 5]);
    check(vec![5, 4, 3, 2, 1]);
}

#[test]
fn duplicates_and_negatives() {
    check(vec![3, -1, 3, 0, -1, -7, 3]);
}

#[test]
fn extremes() {
    check(vec![i32::MAX, 0, i32::MIN, -1, i32::MAX, i32::MIN]);
}

#[test]
fn sorts_in_place_on_a_slice() {
    let mut arr = [3, 1, 2, 9, 8];
    ft_sort_int_tab(&mut arr[1..4]);
    assert_eq!(arr, [3, 1, 2, 9, 8]);
    ft_sort_int_tab(&mut arr[..]);
    assert_eq!(arr, [1, 2, 3, 8, 9]);
}

#[test]
fn bigger() {
    // 결정적인 의사 난수 (LCG)
    let mut x: u32 = 12345;
    let v: Vec<i32> = (0..3000)
        .map(|_| {
            x = x.wrapping_mul(1_103_515_245).wrapping_add(12345);
            (x >> 8) as i32 - 8_000_000
        })
        .collect();
    check(v);
}

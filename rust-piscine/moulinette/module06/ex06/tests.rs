use ex06::{Pairs, PairsExt};

#[test]
fn numbers() {
    let v: Vec<(i32, i32)> = vec![1, 2, 3, 4].into_iter().pairs().collect();
    assert_eq!(v, [(1, 2), (2, 3), (3, 4)]);
}

#[test]
fn too_short() {
    assert_eq!(Vec::<i32>::new().into_iter().pairs().next(), None);
    assert_eq!(vec![7].into_iter().pairs().next(), None);
}

#[test]
fn chars() {
    let v: Vec<String> = "abc"
        .chars()
        .pairs()
        .map(|(a, b)| format!("{a}{b}"))
        .collect();
    assert_eq!(v, ["ab", "bc"]);
}

#[test]
fn infinite_source() {
    let v: Vec<(u32, u32)> = (1..).pairs().take(3).collect();
    assert_eq!(v, [(1, 2), (2, 3), (3, 4)]);
}

#[test]
fn lazy() {
    let mut pulled = 0;
    let it = (0..10).inspect(|_| pulled += 1).pairs();
    let _named: &Pairs<_> = &it;
    drop(it);
    assert_eq!(pulled, 0);
}

#[test]
fn chains_with_std_adapters() {
    let rising = [1, 5, 3, 8, 9]
        .iter()
        .pairs()
        .filter(|(a, b)| b > a)
        .count();
    assert_eq!(rising, 3);
}

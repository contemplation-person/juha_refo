use ex07::fibonacci;

#[test]
fn base_cases() {
    assert_eq!(fibonacci(0), 0);
    assert_eq!(fibonacci(1), 1);
}

#[test]
fn small() {
    let want = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55];
    for (n, w) in want.iter().enumerate() {
        assert_eq!(fibonacci(n as u32), *w, "fibonacci({n})");
    }
}

#[test]
fn fast_enough() {
    assert_eq!(fibonacci(50), 12_586_269_025);
    assert_eq!(fibonacci(80), 23_416_728_348_467_685);
}

#[test]
fn largest_u64() {
    assert_eq!(fibonacci(93), 12_200_160_415_121_876_738);
}

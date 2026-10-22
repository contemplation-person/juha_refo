use ex01::parallel_sum;

#[test]
fn empty() {
    assert_eq!(parallel_sum(&[], 4), 0);
}

#[test]
fn one_thread() {
    assert_eq!(parallel_sum(&[1, 2, 3, 4], 1), 10);
}

#[test]
fn uneven_split() {
    let v: Vec<u64> = (1..=10).collect();
    for t in 1..=12 {
        assert_eq!(parallel_sum(&v, t), 55, "threads = {t}");
    }
}

#[test]
fn more_threads_than_numbers() {
    assert_eq!(parallel_sum(&[7], 8), 7);
    assert_eq!(parallel_sum(&[1, 2], 100), 3);
}

#[test]
fn big() {
    let v: Vec<u64> = (0..1_000_000).collect();
    assert_eq!(parallel_sum(&v, 8), 499_999_500_000);
}

use ex04::is_prime;

#[test]
fn not_prime_by_definition() {
    assert!(!is_prime(0));
    assert!(!is_prime(1));
}

#[test]
fn small_primes() {
    for p in [2, 3, 5, 7, 11, 13, 97] {
        assert!(is_prime(p), "{p} is prime");
    }
}

#[test]
fn small_composites() {
    for n in [4, 6, 9, 15, 25, 49, 91, 100] {
        assert!(!is_prime(n), "{n} is not prime");
    }
}

#[test]
fn count_below_10000() {
    assert_eq!((0..10_000).filter(|&n| is_prime(n)).count(), 1229);
}

#[test]
fn big_primes() {
    assert!(is_prime(2_147_483_647));
    assert!(is_prime(1_000_000_007));
    assert!(is_prime(999_999_999_989));
}

#[test]
fn big_composites() {
    assert!(!is_prime(999_999_999_991));
    assert!(!is_prime(u64::MAX));
}

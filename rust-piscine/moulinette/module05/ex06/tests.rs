use ex06::{Countdown, Fibonacci};

#[test]
fn countdown() {
    let v: Vec<u32> = Countdown::new(3).collect();
    assert_eq!(v, [3, 2, 1]);
}

#[test]
fn countdown_zero() {
    let mut c = Countdown::new(0);
    assert_eq!(c.next(), None);
    assert_eq!(c.next(), None);
}

#[test]
fn countdown_with_adapters() {
    let sum: u32 = Countdown::new(100).sum();
    assert_eq!(sum, 5050);
    let evens: Vec<u32> = Countdown::new(6).filter(|n| n % 2 == 0).collect();
    assert_eq!(evens, [6, 4, 2]);
}

#[test]
fn fibonacci_start() {
    let v: Vec<u64> = Fibonacci::new().take(10).collect();
    assert_eq!(v, [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]);
}

#[test]
fn fibonacci_default() {
    assert_eq!(Fibonacci::default().nth(10), Some(55));
}

#[test]
fn fibonacci_stops_before_overflow() {
    let mut f = Fibonacci::new();
    assert_eq!(f.by_ref().count(), 94);
    assert_eq!(f.next(), None);
    assert_eq!(Fibonacci::new().last(), Some(12_200_160_415_121_876_738));
}

use ex03::collatz_steps;

#[test]
fn zero_and_one() {
    assert_eq!(collatz_steps(0), 0);
    assert_eq!(collatz_steps(1), 0);
}

#[test]
fn small() {
    assert_eq!(collatz_steps(2), 1);
    assert_eq!(collatz_steps(6), 8);
    assert_eq!(collatz_steps(7), 16);
}

#[test]
fn famous_27() {
    assert_eq!(collatz_steps(27), 111);
}

#[test]
fn needs_u64() {
    assert_eq!(collatz_steps(670_617_279), 986);
}

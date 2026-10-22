use ex03::Fraction;

#[test]
fn reduces() {
    let f = Fraction::new(6, 8);
    assert_eq!(f.numerator(), 3);
    assert_eq!(f.denominator(), 4);
    assert_eq!(Fraction::new(2, 4), Fraction::new(1, 2));
}

#[test]
fn sign_goes_to_numerator() {
    let f = Fraction::new(1, -2);
    assert_eq!((f.numerator(), f.denominator()), (-1, 2));
    let g = Fraction::new(-3, -9);
    assert_eq!((g.numerator(), g.denominator()), (1, 3));
}

#[test]
fn zero() {
    let z = Fraction::new(0, -5);
    assert_eq!((z.numerator(), z.denominator()), (0, 1));
    assert_eq!(z.to_string(), "0");
}

#[test]
fn display() {
    assert_eq!(Fraction::new(3, 4).to_string(), "3/4");
    assert_eq!(Fraction::new(10, -4).to_string(), "-5/2");
    assert_eq!(Fraction::new(8, 4).to_string(), "2");
    assert_eq!(Fraction::new(-7, 1).to_string(), "-7");
    assert_eq!(format!("[{}]", Fraction::new(1, 3)), "[1/3]");
}

#[test]
fn copy_and_debug() {
    let a = Fraction::new(1, 2);
    let b = a;
    assert_eq!(a, b);
    assert!(!format!("{a:?}").is_empty());
}

#[test]
#[should_panic]
fn zero_denominator_panics() {
    Fraction::new(1, 0);
}

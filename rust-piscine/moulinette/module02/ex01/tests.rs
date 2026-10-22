use ex01::Rectangle;

#[test]
fn new_and_fields() {
    let r = Rectangle::new(30, 50);
    assert_eq!(r.width, 30);
    assert_eq!(r.height, 50);
}

#[test]
fn square() {
    assert_eq!(Rectangle::square(7), Rectangle { width: 7, height: 7 });
}

#[test]
fn area_and_perimeter() {
    let r = Rectangle::new(30, 50);
    assert_eq!(r.area(), 1500);
    assert_eq!(r.perimeter(), 160);
}

#[test]
fn zero_size() {
    let r = Rectangle::new(0, 10);
    assert_eq!(r.area(), 0);
    assert_eq!(r.perimeter(), 20);
}

#[test]
fn no_overflow() {
    let r = Rectangle::new(u32::MAX, u32::MAX);
    assert_eq!(r.area(), 18_446_744_065_119_617_025);
    assert_eq!(r.perimeter(), 17_179_869_180);
}

#[test]
fn can_hold() {
    let big = Rectangle::new(30, 50);
    let small = Rectangle::new(10, 40);
    let wide = Rectangle::new(60, 45);
    assert!(big.can_hold(&small));
    assert!(!small.can_hold(&big));
    assert!(!big.can_hold(&wide));
}

#[test]
fn can_hold_is_strict() {
    let r = Rectangle::new(10, 10);
    assert!(!r.can_hold(&Rectangle::new(10, 5)));
    assert!(!r.can_hold(&Rectangle::square(10)));
}

#[test]
fn debug_output() {
    assert_eq!(
        format!("{:?}", Rectangle::new(1, 2)),
        "Rectangle { width: 1, height: 2 }"
    );
}

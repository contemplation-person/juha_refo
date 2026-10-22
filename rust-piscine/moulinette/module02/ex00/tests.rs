use ex00::Point;

fn close(a: f64, b: f64) -> bool {
    (a - b).abs() < 1e-9
}

#[test]
fn new_and_fields() {
    let p = Point::new(1.5, -2.0);
    assert_eq!(p.x, 1.5);
    assert_eq!(p.y, -2.0);
}

#[test]
fn origin() {
    assert_eq!(Point::origin(), Point { x: 0.0, y: 0.0 });
}

#[test]
fn distance_345() {
    let a = Point::new(0.0, 0.0);
    let b = Point::new(3.0, 4.0);
    assert!(close(a.distance(&b), 5.0));
    assert!(close(b.distance(&a), 5.0));
}

#[test]
fn distance_to_self_is_zero() {
    let p = Point::new(-7.25, 3.5);
    assert!(close(p.distance(&p), 0.0));
}

#[test]
fn distance_negative_coords() {
    let a = Point::new(-1.0, -1.0);
    let b = Point::new(2.0, 3.0);
    assert!(close(a.distance(&b), 5.0));
}

#[test]
fn translate_moves_in_place() {
    let mut p = Point::new(1.0, 1.0);
    p.translate(2.0, -3.0);
    assert_eq!(p, Point::new(3.0, -2.0));
}

#[test]
fn copy_and_debug() {
    let a = Point::new(1.0, 2.0);
    let b = a;
    assert_eq!(a, b);
    assert_eq!(format!("{a:?}"), "Point { x: 1.0, y: 2.0 }");
}

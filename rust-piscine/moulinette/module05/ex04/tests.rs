use ex04::Vector2;

#[test]
fn add_sub() {
    let a = Vector2::new(1.0, 2.0);
    let b = Vector2::new(3.0, -4.0);
    assert_eq!(a + b, Vector2::new(4.0, -2.0));
    assert_eq!(a - b, Vector2::new(-2.0, 6.0));
}

#[test]
fn scalar_mul() {
    assert_eq!(Vector2::new(1.5, -2.0) * 2.0, Vector2::new(3.0, -4.0));
}

#[test]
fn neg() {
    assert_eq!(-Vector2::new(1.0, -2.0), Vector2::new(-1.0, 2.0));
}

#[test]
fn add_assign() {
    let mut v = Vector2::new(1.0, 1.0);
    v += Vector2::new(2.0, 3.0);
    v += Vector2::new(-1.0, 0.0);
    assert_eq!(v, Vector2::new(2.0, 4.0));
}

#[test]
fn copy_semantics() {
    let a = Vector2::new(1.0, 2.0);
    let b = a + a;
    assert_eq!(a.x, 1.0);
    assert_eq!(b.y, 4.0);
}

#[test]
fn dot_and_length() {
    let a = Vector2::new(3.0, 4.0);
    assert_eq!(a.length(), 5.0);
    assert_eq!(a.dot(Vector2::new(2.0, -1.0)), 2.0);
    assert_eq!(Vector2::new(0.0, 0.0).length(), 0.0);
}

#[test]
fn chained() {
    let p = Vector2::new(0.0, 0.0);
    let v = Vector2::new(1.0, 2.0);
    assert_eq!(p + v * 3.0 - Vector2::new(1.0, 1.0), Vector2::new(2.0, 5.0));
}

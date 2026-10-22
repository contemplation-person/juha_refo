use ex02::Shape;
use std::f64::consts::PI;

fn close(a: f64, b: f64) -> bool {
    (a - b).abs() < 1e-9
}

#[test]
fn circle() {
    let c = Shape::Circle { radius: 2.0 };
    assert!(close(c.area(), 4.0 * PI));
    assert!(close(c.perimeter(), 4.0 * PI));
}

#[test]
fn rectangle() {
    let r = Shape::Rectangle {
        width: 3.0,
        height: 4.5,
    };
    assert!(close(r.area(), 13.5));
    assert!(close(r.perimeter(), 15.0));
}

#[test]
fn right_triangle() {
    let t = Shape::Triangle {
        a: 3.0,
        b: 4.0,
        c: 5.0,
    };
    assert!(close(t.area(), 6.0));
    assert!(close(t.perimeter(), 12.0));
}

#[test]
fn equilateral_triangle() {
    let t = Shape::Triangle {
        a: 2.0,
        b: 2.0,
        c: 2.0,
    };
    assert!(close(t.area(), 3.0_f64.sqrt()));
}

#[test]
fn mixed_list() {
    let shapes = [
        Shape::Circle { radius: 1.0 },
        Shape::Rectangle {
            width: 2.0,
            height: 2.0,
        },
        Shape::Triangle {
            a: 3.0,
            b: 4.0,
            c: 5.0,
        },
    ];
    let total: f64 = shapes.iter().map(|s| s.area()).sum();
    assert!(close(total, PI + 4.0 + 6.0));
}

use ex05::{Circle, Shape, Square, Triangle, largest_name, total_area};

fn close(a: f64, b: f64) -> bool {
    (a - b).abs() < 1e-9
}

#[test]
fn areas() {
    assert!(close(Square { side: 3.0 }.area(), 9.0));
    assert!(close(
        Triangle {
            base: 4.0,
            height: 5.0
        }
        .area(),
        10.0
    ));
    assert!(close(
        Circle { radius: 2.0 }.area(),
        4.0 * std::f64::consts::PI
    ));
}

#[test]
fn names() {
    assert_eq!(Circle { radius: 1.0 }.name(), "circle");
    assert_eq!(Square { side: 1.0 }.name(), "square");
    assert_eq!(
        Triangle {
            base: 1.0,
            height: 1.0
        }
        .name(),
        "triangle"
    );
}

#[test]
fn total() {
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Square { side: 2.0 }),
        Box::new(Triangle {
            base: 3.0,
            height: 2.0,
        }),
        Box::new(Circle { radius: 1.0 }),
    ];
    assert!(close(total_area(&shapes), 7.0 + std::f64::consts::PI));
    assert!(close(total_area(&[]), 0.0));
}

#[test]
fn largest() {
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Square { side: 1.0 }),
        Box::new(Circle { radius: 1.0 }),
        Box::new(Triangle {
            base: 2.0,
            height: 2.0,
        }),
    ];
    assert_eq!(largest_name(&shapes), Some(String::from("circle")));
    assert_eq!(largest_name(&[]), None);
}

#[test]
fn largest_tie_keeps_first() {
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Triangle {
            base: 2.0,
            height: 4.0,
        }),
        Box::new(Square { side: 2.0 }),
    ];
    assert_eq!(largest_name(&shapes), Some(String::from("triangle")));
}

#[test]
fn user_defined_shape() {
    struct Dot;
    impl Shape for Dot {
        fn area(&self) -> f64 {
            0.0
        }
        fn name(&self) -> String {
            String::from("dot")
        }
    }
    let shapes: Vec<Box<dyn Shape>> = vec![Box::new(Dot)];
    assert_eq!(largest_name(&shapes), Some(String::from("dot")));
}

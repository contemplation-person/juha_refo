use ex06::{Direction, Robot};

#[test]
fn new_robot() {
    let r = Robot::new(3, -2, Direction::West);
    assert_eq!((r.x, r.y, r.facing), (3, -2, Direction::West));
}

#[test]
fn turn_right_cycle() {
    let mut r = Robot::new(0, 0, Direction::North);
    r.turn_right();
    assert_eq!(r.facing, Direction::East);
    r.turn_right();
    assert_eq!(r.facing, Direction::South);
    r.turn_right();
    assert_eq!(r.facing, Direction::West);
    r.turn_right();
    assert_eq!(r.facing, Direction::North);
}

#[test]
fn turn_left_cycle() {
    let mut r = Robot::new(0, 0, Direction::North);
    r.turn_left();
    assert_eq!(r.facing, Direction::West);
    r.turn_left();
    assert_eq!(r.facing, Direction::South);
    r.turn_left();
    assert_eq!(r.facing, Direction::East);
    r.turn_left();
    assert_eq!(r.facing, Direction::North);
}

#[test]
fn advance_each_direction() {
    let cases = [
        (Direction::North, (0, 1)),
        (Direction::East, (1, 0)),
        (Direction::South, (0, -1)),
        (Direction::West, (-1, 0)),
    ];
    for (dir, pos) in cases {
        let mut r = Robot::new(0, 0, dir);
        r.advance();
        assert_eq!((r.x, r.y), pos, "facing {dir:?}");
        assert_eq!(r.facing, dir);
    }
}

#[test]
fn execute_program() {
    let mut r = Robot::new(7, 3, Direction::North);
    r.execute("RAALAL");
    assert_eq!((r.x, r.y, r.facing), (9, 4, Direction::West));
}

#[test]
fn execute_ignores_unknown() {
    let mut r = Robot::new(0, 0, Direction::East);
    r.execute("A?A x L-A");
    assert_eq!((r.x, r.y, r.facing), (2, 1, Direction::North));
}

#[test]
fn execute_empty() {
    let mut r = Robot::new(1, 1, Direction::South);
    r.execute("");
    assert_eq!((r.x, r.y, r.facing), (1, 1, Direction::South));
}

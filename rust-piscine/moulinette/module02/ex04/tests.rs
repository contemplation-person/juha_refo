use ex04::Light;

#[test]
fn cycle() {
    assert_eq!(Light::Red.next(), Light::Green);
    assert_eq!(Light::Green.next(), Light::Yellow);
    assert_eq!(Light::Yellow.next(), Light::Red);
}

#[test]
fn three_steps_back_home() {
    for start in [Light::Red, Light::Yellow, Light::Green] {
        assert_eq!(start.next().next().next(), start);
    }
}

#[test]
fn durations() {
    assert_eq!(Light::Red.duration(), 60);
    assert_eq!(Light::Green.duration(), 45);
    assert_eq!(Light::Yellow.duration(), 5);
}

#[test]
fn can_go() {
    assert!(Light::Green.can_go());
    assert!(!Light::Yellow.can_go());
    assert!(!Light::Red.can_go());
}

#[test]
fn after_short() {
    assert_eq!(Light::after(Light::Red, 0), Light::Red);
    assert_eq!(Light::after(Light::Red, 59), Light::Red);
    assert_eq!(Light::after(Light::Red, 60), Light::Green);
    assert_eq!(Light::after(Light::Red, 104), Light::Green);
    assert_eq!(Light::after(Light::Red, 105), Light::Yellow);
    assert_eq!(Light::after(Light::Red, 110), Light::Red);
}

#[test]
fn after_from_other_start() {
    assert_eq!(Light::after(Light::Yellow, 4), Light::Yellow);
    assert_eq!(Light::after(Light::Yellow, 5), Light::Red);
    assert_eq!(Light::after(Light::Green, 50), Light::Red);
}

#[test]
fn after_long_time() {
    assert_eq!(Light::after(Light::Red, 110 * 1_000_000 + 61), Light::Green);
    assert_eq!(Light::after(Light::Green, u32::MAX), Light::after(Light::Green, u32::MAX % 110));
}

#[test]
fn copy_and_debug() {
    let a = Light::Red;
    let b = a;
    assert_eq!(a, b);
    assert_eq!(format!("{:?}", Light::Yellow), "Yellow");
}

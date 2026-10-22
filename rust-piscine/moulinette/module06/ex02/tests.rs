use ex02::{call_n_times, make_adder, make_counter};

#[test]
fn counter_counts() {
    let mut c = make_counter();
    assert_eq!(c(), 1);
    assert_eq!(c(), 2);
    assert_eq!(c(), 3);
}

#[test]
fn counters_are_independent() {
    let mut a = make_counter();
    let mut b = make_counter();
    a();
    a();
    assert_eq!(a(), 3);
    assert_eq!(b(), 1);
}

#[test]
fn adder() {
    let add5 = make_adder(5);
    let sub3 = make_adder(-3);
    assert_eq!(add5(10), 15);
    assert_eq!(add5(0), 5);
    assert_eq!(sub3(10), 7);
}

#[test]
fn adder_is_fn() {
    fn twice(f: impl Fn(i32) -> i32, x: i32) -> i32 {
        f(f(x))
    }
    assert_eq!(twice(make_adder(4), 1), 9);
}

#[test]
fn call_n_times_mutates() {
    let mut log = Vec::new();
    call_n_times(3, || log.push("hi"));
    assert_eq!(log, ["hi", "hi", "hi"]);
    call_n_times(0, || panic!("must not be called"));
}

#[test]
fn call_n_times_with_counter() {
    let mut c = make_counter();
    call_n_times(4, || {
        c();
    });
    assert_eq!(c(), 5);
}

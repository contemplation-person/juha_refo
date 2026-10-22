use ex00::spawn_squares;
use std::thread;

#[test]
fn zero_threads() {
    assert!(spawn_squares(0).is_empty());
}

#[test]
fn results_in_order() {
    let handles = spawn_squares(10);
    assert_eq!(handles.len(), 10);
    let got: Vec<u64> = handles.into_iter().map(|h| h.join().unwrap()).collect();
    assert_eq!(got, [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]);
}

#[test]
fn really_other_threads() {
    let me = thread::current().id();
    for h in spawn_squares(4) {
        assert_ne!(h.thread().id(), me);
        h.join().unwrap();
    }
}

#[test]
fn many() {
    let total: u64 = spawn_squares(200)
        .into_iter()
        .map(|h| h.join().unwrap())
        .sum();
    assert_eq!(total, (0..200u64).map(|i| i * i).sum::<u64>());
}

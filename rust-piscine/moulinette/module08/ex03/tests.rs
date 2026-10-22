use ex03::{collect_ids, count_together};

#[test]
fn no_threads() {
    assert_eq!(count_together(0, 100), 0);
    assert!(collect_ids(0).is_empty());
}

#[test]
fn one_thread() {
    assert_eq!(count_together(1, 1000), 1000);
}

#[test]
fn no_lost_updates() {
    assert_eq!(count_together(8, 10_000), 80_000);
    assert_eq!(count_together(50, 100), 5_000);
}

#[test]
fn every_id_once() {
    let ids = collect_ids(16);
    assert_eq!(ids, (0..16).collect::<Vec<_>>());
}

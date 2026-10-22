use ex02::{fan_in, start_producer};

fn strings(items: &[&str]) -> Vec<String> {
    items.iter().map(|s| s.to_string()).collect()
}

#[test]
fn producer_keeps_order() {
    let rx = start_producer(strings(&["a", "b", "c"]));
    let got: Vec<String> = rx.iter().collect();
    assert_eq!(got, ["a", "b", "c"]);
}

#[test]
fn producer_empty() {
    let rx = start_producer(Vec::new());
    assert!(rx.recv().is_err());
}

#[test]
fn producer_many() {
    let items: Vec<String> = (0..1000).map(|i| i.to_string()).collect();
    let got: Vec<String> = start_producer(items.clone()).into_iter().collect();
    assert_eq!(got, items);
}

#[test]
fn fan_in_collects_everything_sorted() {
    let got = fan_in(3, 2);
    assert_eq!(got, [(0, 0), (0, 1), (1, 0), (1, 1), (2, 0), (2, 1)]);
}

#[test]
fn fan_in_edges() {
    assert!(fan_in(0, 5).is_empty());
    assert!(fan_in(5, 0).is_empty());
}

#[test]
fn fan_in_big() {
    let got = fan_in(8, 500);
    assert_eq!(got.len(), 4000);
    let mut want = Vec::new();
    for id in 0..8 {
        for k in 0..500 {
            want.push((id, k));
        }
    }
    assert_eq!(got, want);
}

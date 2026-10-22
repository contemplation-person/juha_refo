use ex00::{ft_foreach, ft_map};

#[test]
fn foreach_visits_in_order() {
    let mut seen = Vec::new();
    ft_foreach(&[3, 1, 4, 1, 5], |x| seen.push(*x));
    assert_eq!(seen, [3, 1, 4, 1, 5]);
}

#[test]
fn foreach_empty() {
    let mut calls = 0;
    let empty: [i32; 0] = [];
    ft_foreach(&empty, |_| calls += 1);
    assert_eq!(calls, 0);
}

#[test]
fn foreach_strings() {
    let words = [String::from("ab"), String::from("cde")];
    let mut total = 0;
    ft_foreach(&words, |w| total += w.len());
    assert_eq!(total, 5);
}

#[test]
fn map_same_type() {
    assert_eq!(ft_map(&[1, 2, 3], |x| x * 10), [10, 20, 30]);
}

#[test]
fn map_changes_type() {
    let got: Vec<String> = ft_map(&[1, 22, 333], |x| x.to_string());
    assert_eq!(got, ["1", "22", "333"]);
    let lens = ft_map(&["a", "bb", ""], |s| s.len());
    assert_eq!(lens, [1, 2, 0]);
}

#[test]
fn map_with_state() {
    let mut i = 0;
    let got = ft_map(&['a', 'b', 'c'], |c| {
        i += 1;
        format!("{i}{c}")
    });
    assert_eq!(got, ["1a", "2b", "3c"]);
}

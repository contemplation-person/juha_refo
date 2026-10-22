use ex06::Company;

fn names(v: &[&str]) -> Vec<String> {
    v.iter().map(|x| x.to_string()).collect()
}

fn sample() -> Company {
    let mut c = Company::new();
    assert!(c.execute("Add Sally to Engineering"));
    assert!(c.execute("Add Amir to Sales"));
    assert!(c.execute("Add Bob to Engineering"));
    c
}

#[test]
fn department_is_sorted() {
    let c = sample();
    assert_eq!(c.department("Engineering"), names(&["Bob", "Sally"]));
    assert_eq!(c.department("Sales"), names(&["Amir"]));
}

#[test]
fn unknown_department_is_empty() {
    let c = sample();
    assert!(c.department("Marketing").is_empty());
    assert!(c.department("engineering").is_empty());
}

#[test]
fn all_is_sorted_by_department() {
    let c = sample();
    let want = vec![
        ("Engineering".to_string(), names(&["Bob", "Sally"])),
        ("Sales".to_string(), names(&["Amir"])),
    ];
    assert_eq!(c.all(), want);
}

#[test]
fn bad_commands_change_nothing() {
    let mut c = sample();
    for cmd in [
        "",
        "Add Sally Engineering",
        "add Tom to Sales",
        "Add Tom into Sales",
        "Add Tom to Sales now",
        "Remove Sally from Engineering",
        "Add to Sales",
    ] {
        assert!(!c.execute(cmd), "{cmd:?} must be rejected");
    }
    assert_eq!(c.all(), sample().all());
}

#[test]
fn duplicate_is_rejected() {
    let mut c = sample();
    assert!(!c.execute("Add Sally to Engineering"));
    assert_eq!(c.department("Engineering"), names(&["Bob", "Sally"]));
    assert!(c.execute("Add Sally to Sales"));
    assert_eq!(c.department("Sales"), names(&["Amir", "Sally"]));
}

#[test]
fn extra_whitespace_is_fine() {
    let mut c = Company::new();
    assert!(c.execute("   Add   Tom \t to  Ops  "));
    assert_eq!(c.department("Ops"), names(&["Tom"]));
}

#[test]
fn default_is_empty() {
    let c = Company::default();
    assert!(c.all().is_empty());
}

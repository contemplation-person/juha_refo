use ex02::{Article, Summary, Tweet, notify};

fn tweet() -> Tweet {
    Tweet {
        username: String::from("ferris"),
        content: String::from("hello, crab world"),
    }
}

fn article() -> Article {
    Article {
        title: String::from("Rust 1.98 released"),
        author: String::from("The Rust Team"),
        content: String::from("..."),
    }
}

#[test]
fn tweet_author() {
    assert_eq!(tweet().author(), "@ferris");
}

#[test]
fn tweet_overrides_summarize() {
    assert_eq!(tweet().summarize(), "@ferris: hello, crab world");
}

#[test]
fn article_author() {
    assert_eq!(article().author(), "The Rust Team");
}

#[test]
fn article_uses_default_summarize() {
    assert_eq!(article().summarize(), "(Read more from The Rust Team...)");
}

#[test]
fn notify_any_summary() {
    assert_eq!(
        notify(&tweet()),
        "Breaking news! @ferris: hello, crab world"
    );
    assert_eq!(
        notify(&article()),
        "Breaking news! (Read more from The Rust Team...)"
    );
}

#[test]
fn trait_is_implementable_outside() {
    struct Anon;
    impl Summary for Anon {
        fn author(&self) -> String {
            String::from("nobody")
        }
    }
    assert_eq!(notify(&Anon), "Breaking news! (Read more from nobody...)");
    assert_eq!(article().title, "Rust 1.98 released");
}

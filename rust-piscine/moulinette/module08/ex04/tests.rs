use ex04::ThreadPool;
use std::collections::HashSet;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::{Arc, Barrier, Mutex};
use std::thread;

#[test]
fn runs_every_job_before_drop_returns() {
    let counter = Arc::new(AtomicUsize::new(0));
    let pool = ThreadPool::new(4);
    for _ in 0..100 {
        let c = Arc::clone(&counter);
        pool.execute(move || {
            c.fetch_add(1, Ordering::SeqCst);
        });
    }
    drop(pool);
    assert_eq!(counter.load(Ordering::SeqCst), 100);
}

#[test]
fn jobs_run_at_the_same_time() {
    // 네 작업이 모두 동시에 barrier 에 도착해야 풀려난다.
    // 한 번에 하나씩 돌리면 여기서 영원히 멈춘다.
    let barrier = Arc::new(Barrier::new(4));
    let done = Arc::new(AtomicUsize::new(0));
    let pool = ThreadPool::new(4);
    for _ in 0..4 {
        let b = Arc::clone(&barrier);
        let d = Arc::clone(&done);
        pool.execute(move || {
            b.wait();
            d.fetch_add(1, Ordering::SeqCst);
        });
    }
    drop(pool);
    assert_eq!(done.load(Ordering::SeqCst), 4);
}

#[test]
fn uses_at_most_size_threads_and_not_the_caller() {
    let ids = Arc::new(Mutex::new(HashSet::new()));
    let pool = ThreadPool::new(3);
    for _ in 0..30 {
        let ids = Arc::clone(&ids);
        pool.execute(move || {
            ids.lock().unwrap().insert(thread::current().id());
        });
    }
    drop(pool);
    let ids = ids.lock().unwrap();
    assert!(!ids.is_empty());
    assert!(ids.len() <= 3, "used {} threads", ids.len());
    assert!(!ids.contains(&thread::current().id()));
}

#[test]
#[should_panic]
fn zero_size_panics() {
    ThreadPool::new(0);
}

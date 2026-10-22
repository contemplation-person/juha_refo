use ex02::fizzbuzz;

#[test]
fn numbers() {
    assert_eq!(fizzbuzz(1), "1");
    assert_eq!(fizzbuzz(2), "2");
    assert_eq!(fizzbuzz(98), "98");
}

#[test]
fn fizz() {
    assert_eq!(fizzbuzz(3), "Fizz");
    assert_eq!(fizzbuzz(99), "Fizz");
}

#[test]
fn buzz() {
    assert_eq!(fizzbuzz(5), "Buzz");
    assert_eq!(fizzbuzz(100), "Buzz");
}

#[test]
fn fizzbuzz_both() {
    assert_eq!(fizzbuzz(15), "FizzBuzz");
    assert_eq!(fizzbuzz(45), "FizzBuzz");
}

#[test]
fn zero() {
    assert_eq!(fizzbuzz(0), "FizzBuzz");
}

#[test]
fn first_fifteen() {
    let got: Vec<String> = (1..=15).map(fizzbuzz).collect();
    let want = [
        "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14",
        "FizzBuzz",
    ];
    assert_eq!(got, want);
}

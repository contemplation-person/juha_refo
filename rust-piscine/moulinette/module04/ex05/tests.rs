use ex05::{CalcError, eval_rpn};
use std::error::Error;

#[test]
fn simple() {
    assert_eq!(eval_rpn("3 4 +"), Ok(7));
    assert_eq!(eval_rpn("2 3 4 * +"), Ok(14));
    assert_eq!(eval_rpn("5 1 2 + 4 * + 3 -"), Ok(14));
    assert_eq!(eval_rpn("  42  "), Ok(42));
}

#[test]
fn operand_order() {
    assert_eq!(eval_rpn("10 3 -"), Ok(7));
    assert_eq!(eval_rpn("10 3 /"), Ok(3));
}

#[test]
fn negative_numbers() {
    assert_eq!(eval_rpn("-3 -4 *"), Ok(12));
    assert_eq!(eval_rpn("-7 2 /"), Ok(-3));
    assert_eq!(eval_rpn("1 -1 -"), Ok(2));
}

#[test]
fn empty() {
    assert_eq!(eval_rpn(""), Err(CalcError::Empty));
    assert_eq!(eval_rpn(" \t\n"), Err(CalcError::Empty));
}

#[test]
fn not_enough_operands() {
    assert_eq!(eval_rpn("+"), Err(CalcError::NotEnoughOperands));
    assert_eq!(eval_rpn("1 +"), Err(CalcError::NotEnoughOperands));
    assert_eq!(eval_rpn("1 2 + *"), Err(CalcError::NotEnoughOperands));
}

#[test]
fn too_many_operands() {
    assert_eq!(eval_rpn("1 2"), Err(CalcError::TooManyOperands));
    assert_eq!(eval_rpn("1 2 3 +"), Err(CalcError::TooManyOperands));
}

#[test]
fn division_by_zero() {
    assert_eq!(eval_rpn("1 0 /"), Err(CalcError::DivisionByZero));
}

#[test]
fn invalid_token() {
    assert_eq!(eval_rpn("1 2 x +"), Err(CalcError::InvalidToken("x".to_string())));
    assert_eq!(eval_rpn("1 2 ++"), Err(CalcError::InvalidToken("++".to_string())));
    assert_eq!(eval_rpn("4 2 %"), Err(CalcError::InvalidToken("%".to_string())));
    assert_eq!(
        eval_rpn("99999999999999999999"),
        Err(CalcError::InvalidToken("99999999999999999999".to_string()))
    );
}

#[test]
fn overflow() {
    assert_eq!(eval_rpn("9223372036854775807 1 +"), Err(CalcError::Overflow));
    assert_eq!(eval_rpn("-9223372036854775808 1 -"), Err(CalcError::Overflow));
    assert_eq!(eval_rpn("4611686018427387904 2 *"), Err(CalcError::Overflow));
    assert_eq!(eval_rpn("-9223372036854775808 -1 /"), Err(CalcError::Overflow));
}

#[test]
fn first_error_wins() {
    assert_eq!(eval_rpn("1 x"), Err(CalcError::InvalidToken("x".to_string())));
    assert_eq!(eval_rpn("1 0 / x"), Err(CalcError::DivisionByZero));
    assert_eq!(eval_rpn("+ x"), Err(CalcError::NotEnoughOperands));
}

#[test]
fn display() {
    assert_eq!(CalcError::Empty.to_string(), "empty expression");
    assert_eq!(
        CalcError::InvalidToken("abc".to_string()).to_string(),
        "invalid token: abc"
    );
    assert_eq!(CalcError::NotEnoughOperands.to_string(), "not enough operands");
    assert_eq!(CalcError::DivisionByZero.to_string(), "division by zero");
    assert_eq!(CalcError::Overflow.to_string(), "overflow");
    assert_eq!(CalcError::TooManyOperands.to_string(), "too many operands");
}

#[test]
fn is_std_error() {
    let e: Box<dyn Error> = Box::new(CalcError::DivisionByZero);
    assert_eq!(e.to_string(), "division by zero");
}

use ex05::Temperature;

fn close(a: f64, b: f64) -> bool {
    (a - b).abs() < 1e-9
}

#[test]
fn to_celsius() {
    assert!(close(Temperature::Celsius(21.5).to_celsius(), 21.5));
    assert!(close(Temperature::Fahrenheit(212.0).to_celsius(), 100.0));
    assert!(close(Temperature::Fahrenheit(-40.0).to_celsius(), -40.0));
    assert!(close(Temperature::Kelvin(273.15).to_celsius(), 0.0));
    assert!(close(Temperature::Kelvin(0.0).to_celsius(), -273.15));
}

#[test]
fn describe_celsius() {
    assert_eq!(Temperature::Celsius(-10.0).describe(), "freezing");
    assert_eq!(Temperature::Celsius(-0.5).describe(), "freezing");
    assert_eq!(Temperature::Celsius(0.0).describe(), "cold");
    assert_eq!(Temperature::Celsius(14.9).describe(), "cold");
    assert_eq!(Temperature::Celsius(15.0).describe(), "mild");
    assert_eq!(Temperature::Celsius(24.9).describe(), "mild");
    assert_eq!(Temperature::Celsius(25.0).describe(), "hot");
}

#[test]
fn describe_other_units() {
    assert_eq!(Temperature::Fahrenheit(32.0).describe(), "cold");
    assert_eq!(Temperature::Fahrenheit(100.0).describe(), "hot");
    assert_eq!(Temperature::Kelvin(300.0).describe(), "hot");
    assert_eq!(Temperature::Kelvin(200.0).describe(), "freezing");
}

#[test]
fn impossible_temperature() {
    assert_eq!(Temperature::Kelvin(-1.0).describe(), "impossible");
    assert_eq!(Temperature::Celsius(-300.0).describe(), "impossible");
    assert_eq!(Temperature::Fahrenheit(-500.0).describe(), "impossible");
}

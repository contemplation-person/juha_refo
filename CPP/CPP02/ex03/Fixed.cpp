#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : raw(0) { }
Fixed::Fixed(int i) : raw(i * (1 << this->fractionalBit)) { }
Fixed::Fixed(float f) : raw(roundf(f * (1 << this->fractionalBit))) { }
Fixed::~Fixed(){ }

Fixed::Fixed(const Fixed& fixed) {
    *this=fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
    if (this != &fixed){
        this->setRawBits(fixed.getRawBits());
    }
    return *this; 
}

float Fixed::toFloat() const {
    return (((float)this->getRawBits()) / (1 << fractionalBit));
}

std::ostream& operator<<(std::ostream& o, const Fixed &fixed) {
    o << fixed.toFloat();
    return o;
}

int Fixed::getRawBits(void) const {
    return this->raw;
}

void Fixed::setRawBits(int const raw) {
    this->raw = raw;
}

int Fixed::toInt() const {
    return this->raw >> 8;
}

//new compare operator
bool Fixed::operator>(const Fixed& lhs) { 
    return this->getRawBits() > lhs.getRawBits();
}

bool Fixed::operator<(const Fixed& lhs) {
    return this->getRawBits() < lhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& lhs) {
    return this->getRawBits() >= lhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& lhs) {
    return this->getRawBits() <= lhs.getRawBits();
}

bool Fixed::operator==(const Fixed& lhs) {
    return this->getRawBits() == lhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& lhs) {
    return this->getRawBits() != lhs.getRawBits();
}

// arithmetic operator
Fixed Fixed::operator+(const Fixed& lhs) {
    Fixed tmp(this->toFloat() + lhs.toFloat());
    return tmp;
}

Fixed Fixed::operator-(const Fixed& lhs) {
    Fixed tmp(this->toFloat() - lhs.toFloat());
    return tmp;
}

Fixed Fixed::operator*(const Fixed& lhs) {
    Fixed tmp((this->toFloat() * lhs.toFloat()));
    return tmp;
}

Fixed Fixed::operator/(const Fixed& lhs) {
    Fixed tmp((this->toFloat() * lhs.toFloat()));
    return tmp;
}

// increment operator && decrement operator
Fixed& Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed& Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return (tmp);
}

// new max min
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
    if (lhs.getRawBits() < rhs.getRawBits())  return (lhs);
    return (rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
    if (lhs.getRawBits() < rhs.getRawBits())  return (lhs);
    return (rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
    if (lhs.getRawBits() > rhs.getRawBits())  return (lhs);
    return (rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
    if (lhs.getRawBits() > rhs.getRawBits())  return (lhs);
    return (rhs);
}
/*
• A static member function min that takes as parameters two references on fixed-point
    numbers, and returns a reference to the smallest one.
• A static member function min that takes as parameters two references to constant
    fixed-point numbers, and returns a reference to the smallest one.
• A static member function max that takes as parameters two references on fixed-point
    numbers, and returns a reference to the greatest one.
• A static member function max that takes as parameters two references to constant
    fixed-point numbers, and returns a reference to the greatest one.
 * */


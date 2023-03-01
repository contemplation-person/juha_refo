#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : raw(0) {
    std::cout << "Default" << std::endl;
}

// new default constructor
Fixed::Fixed(int i) : raw(i) {
    std::cout << "Default" << std::endl;
}

// new default constructor
Fixed::Fixed(float f) : raw(f) {
    std::cout << "Default" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "copy constructor" << std::endl;
    this->raw = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    std::cout << "copy assignment operator" << std::endl;
    this->raw = fixed.getRawBits();
    return *this; 
}

//i don't know
int Fixed::operator<<(const Fixed &fixed) {
   return this->toInt()<<8; 
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits" << std::endl;
    return this->raw;
}

void Fixed::setRawBits(int const raw) {
    this->raw = raw;
}

//output int
int Fixed::toInt() {
    return this->raw;   
}

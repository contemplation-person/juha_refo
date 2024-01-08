#include "Fixed.hpp"

//static 할당 방법;
const int Fixed::fractionalBit = 8;

//Default
Fixed::Fixed() : raw(0) {
    std::cout << "Default" << std::endl;
}

//Destructor
Fixed::~Fixed(){
    std::cout << "Destructor" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed& fixed) {
    std::cout << "copy constructor" << std::endl;
    this->raw = fixed.getRawBits();
}

//copy assignment operator
Fixed& Fixed::operator=(const Fixed &fixed) {
    std::cout << "copy assignment operator" << std::endl;
    this->raw = fixed.getRawBits();
    return *this; 
}

/*
int Fixed::getFractionalBit(void) {
    return (this->fractionalBit);
}
*/

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits" << std::endl;
    return this->raw;
}

void Fixed::setRawBits(int const raw) {
    this->raw = raw;
}

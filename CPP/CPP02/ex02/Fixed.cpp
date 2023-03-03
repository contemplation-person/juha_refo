#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : raw(0) {
    std::cout << "Default" << std::endl;
}

Fixed::Fixed(int i) : raw(i * (1 << this->fractionalBit)) {
    std::cout << "i Default" << std::endl;
}

Fixed::Fixed(float f) : raw(roundf(f * (1 << this->fractionalBit))) {
    std::cout << "f Default" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "copy constructor" << std::endl;
    *this=fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
   std::cout << "copy assignment operator" << std::endl;
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

//new operator
bool Fixed::operator>(const Fixed& lhs, const Fixed& rhs) {
   return lhs.raw > rhs.raw;
}

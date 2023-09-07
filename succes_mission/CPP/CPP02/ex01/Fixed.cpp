#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : raw(0) {
    std::cout << "Default" << std::endl;
}

// new default constructor
Fixed::Fixed(int i) : raw(i * (1 << this->fractionalBit)) {
    std::cout << "i Default" << std::endl;
}

// new default constructor
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

//new float
float Fixed::toFloat() const {
    return (((float)this->getRawBits()) / (1 << fractionalBit));
}
//new operator
std::ostream& operator<<(std::ostream& o, const Fixed &fixed) {
    o << fixed.toFloat(); //static cast << 찾기
    return o;
}

int Fixed::getRawBits(void) const {
    return this->raw;
}

void Fixed::setRawBits(int const raw) {
    this->raw = raw;
}

//output int
int Fixed::toInt() const {
    return this->raw >> 8;
}

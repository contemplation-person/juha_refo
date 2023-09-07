#include <iostream>
#include "Fixed.hpp"

/*
    $> ./a.out
    Default constructor called
    Copy constructor called
    Copy assignment operator called // <-- This line may be missing depending on your implementation
    getRawBits member function called
    Default constructor called
    Copy assignment operator called
    getRawBits member function called
    getRawBits member function called
    0
    getRawBits member function called
    0
    getRawBits member function called
    0
    Destructor called
    Destructor called
    Destructor called
    $>
*/

int main( void ) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
//    c.operator=(b);

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
//  std::cout << a.getFractionalBit() << std::endl;
    return 0;
}

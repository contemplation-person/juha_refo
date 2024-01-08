#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int raw;
    static const int fractionalBit; 

public:
    Fixed();
    ~Fixed();
    Fixed (const Fixed &fiexed); //복사생성자 오버로딩
    Fixed &operator=(const Fixed &fixed); //대입연산자오버로딩
    //int getFractionalBit();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

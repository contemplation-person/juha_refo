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
    Fixed(int i);
    Fixed(float f);
    ~Fixed();
    Fixed (const Fixed &fiexed); //복사생성자 오버로딩
    Fixed &operator=(const Fixed &fixed); //대입연산자오버로딩
    int operator<<(const Fixed &fixed);//i don't know
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    int toInt();
};

#endif

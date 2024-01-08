#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
    float toFloat() const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const ;
};

//프로토 타입은 파라미터 값을 선언하지 않아도 선언해줌
std::ostream& operator<<(std::ostream& o, const Fixed &fixed);

#endif

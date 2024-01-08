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

    Fixed   (const Fixed &fiexed); //복사생성자 오버로딩
    Fixed   &operator=(const Fixed &fixed); //대입연산자오버로딩
    float   toFloat() const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt() const ;

    //new operator
    bool    operator>(const Fixed& lhs);
    bool    operator<(const Fixed& lhs);
    bool    operator>=(const Fixed& lhs);
    bool    operator<=(const Fixed& lhs);
    bool    operator==(const Fixed& lhs);
    bool    operator!=(const Fixed& lhs);

    Fixed operator+(const Fixed& lhs);
    Fixed operator-(const Fixed& lhs);
    Fixed operator*(const Fixed& lhs);
    Fixed operator/(const Fixed& lhs);

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    // new max min
    static Fixed& min(Fixed& lhs, Fixed& rhs);
    static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed& max(Fixed& lhs, Fixed& rhs);
    static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
};

//프로토 타입은 파라미터 값을 선언하지 않아도 선언해줌
std::ostream& operator<<(std::ostream& o, const Fixed &fixed);

#endif

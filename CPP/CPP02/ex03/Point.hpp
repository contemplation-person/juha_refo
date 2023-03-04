#pragma once
#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;
    Point& operator=(const Point& point);
public:
    Point();
    Point(Fixed const x, Fixed const y);
    Point(const Point& point);
    ~Point();
    Fixed getX();
    Fixed getY();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif

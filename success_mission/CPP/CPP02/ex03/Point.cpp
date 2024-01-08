#include "Point.hpp"

Point::Point() : x(0), y(0) {};
Point::Point(Fixed x, Fixed y) : x(x.getRawBits()), y(y.getRawBits()) {};
Point::~Point() {};
Point::Point(const Point& point) {
    *this = point;  
};
Point& Point::operator=(const Point& p) {
    return (*this);
}

Fixed Point::getX() { return this->x; }
Fixed Point::getY() { return this->y; }


#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

std::string Point::toString() {
    std::ostringstream stream;
    stream << "Point{" << "X: " << x << ", Y: " << y << "}";
    return stream.str();
}
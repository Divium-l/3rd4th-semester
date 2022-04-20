#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

std::ostream& operator<<(std::ostream &out, Point& point) {
	out << point.toString();
	return out;
}

std::istream& operator>>(std::istream &in, Point& point) {
    in >> point.x >> point.y;
    return in;
}

bool operator==(Point& p1, Point& p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}


std::string Point::toString() {
    std::ostringstream stream;
    stream << "Point{" << "X: " << x << ", Y: " << y << "}";
    return stream.str();
}
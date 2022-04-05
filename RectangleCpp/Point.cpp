#include "Point.h"

std::string Point::toString() {
    std::ostringstream stream;
    stream << "Point{" << "X: " << x << ", Y: " << y << "}";
    return stream.str();
}
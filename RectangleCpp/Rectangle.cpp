#include "Rectangle.h"

void Rectangle::isValid(Point& firstPoint, Point& secondPoint) {
    if (firstPoint.x == secondPoint.x 
        || firstPoint.y == secondPoint.y)
            throw std::invalid_argument("Rectangle cannot be line or a point");

}

Rectangle::Rectangle(Point firstPoint, Point secondPoint, Color color) {
    isValid(firstPoint, secondPoint);
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->color = color;
}

Point Rectangle::getFirstPoint() {
    return firstPoint;
}

Point Rectangle::getSecondPoint() {
    return secondPoint;
}

Color Rectangle::getColor() {
    return color;
}

void Rectangle::setFirstPoint(Point firstPoint) {
    isValid(firstPoint, this->secondPoint);
    this->firstPoint = firstPoint;
}

void Rectangle::setSecondPoint(Point secondPoint) {
    isValid(this->firstPoint, secondPoint);
    this->secondPoint = secondPoint;
}

void Rectangle::setColor(Color color) {
    this->color = color;
}

std::ostream &operator<<(std::ostream &out, Rectangle &rectangle) {
    out << rectangle.toString();
    return out;
}

std::string Rectangle::toString() {
    std::stringstream stream;
    stream << "Rectangle{"
           << "firstPoint: " << firstPoint.toString()
           << ", secondPoint: " << secondPoint.toString()
           << ", color: " << color.toString() << "}";
    return stream.str();
}

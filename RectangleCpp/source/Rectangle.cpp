#include "../include/Rectangle.h"

void Rectangle::validate(Point& firstPoint, Point& secondPoint) {
    if (firstPoint.x == secondPoint.x 
        || firstPoint.y == secondPoint.y)
            throw std::invalid_argument("Rectangle cannot be line or a point");

}

void Rectangle::validate(int width, int height) {
    if (width < 0 || height < 0)
        throw std::invalid_argument("Width or height cannot be < 0");
}

Rectangle::Rectangle(Point firstPoint, Point secondPoint, Color color) {
    validate(firstPoint, secondPoint);
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->color = color;
}

Rectangle::Rectangle(Point firstPoint, int width, int height, Color color) {
    validate(width, height);
    this->firstPoint = firstPoint;
    this->secondPoint = Point(firstPoint.x + width, firstPoint.y + height);
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
    validate(firstPoint, this->secondPoint);
    this->firstPoint = firstPoint;
}

void Rectangle::setSecondPoint(Point secondPoint) {
    validate(this->firstPoint, secondPoint);
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

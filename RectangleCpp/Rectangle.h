#pragma once

#include <sstream>

#include "Color.h"
#include "Point.h"
#include "Object.h"

//выбрасывать исключение если прямоугольник является линией или точкой

class Rectangle: public Object {
private:
    Point firstPoint;
    Point secondPoint;
    Color color;

public:

    Rectangle(Point firstPoint, Point secondPoint, Color color) {
        this->firstPoint = firstPoint;
        this->secondPoint = secondPoint;
        this->color = color;
    }

    Point getFirstPoint() {
        return firstPoint;
    }

    Point getSecondPoint() {
        return secondPoint;
    }

    Color getColor() {
        return color;
    }

    void setFirstPoint(Point firstPoint) {
        this->firstPoint = firstPoint;
    }

    void setSecondPoint(Point secondPoint) {
        this->secondPoint = secondPoint;
    }

    void setColor(Color color) {
        this->color = color;
    }

    std::string toString() override {
        std::stringstream stream;
        stream << "Rectangle{" << "firstPoint: " << firstPoint.toString()
            << ", secondPoint: " << secondPoint.toString()
            << ", color: " << color.toString() << "}";
        return stream.str();
    }
};


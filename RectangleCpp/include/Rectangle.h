#pragma once

#include <sstream>
#include <stdexcept>

#include "Color.h"
#include "Point.h"
#include "Object.h"

// + выбрасывать исключение если прямоугольник является линией или точкой

class Rectangle: public Object {
private:
    Point firstPoint;
    Point secondPoint;
    Color color;

    void isValid(Point& firstPoint, Point& secondPoint);

public:

    Rectangle(Point firstPoint, Point secondPoint, Color color);

    Point getFirstPoint();

    Point getSecondPoint();

    Color getColor();

    void setFirstPoint(Point firstPoint);

    void setSecondPoint(Point secondPoint);

    void setColor(Color color);

	friend std::ostream& operator<<(std::ostream &out, Rectangle& rectangle);

    std::string toString() override;
};


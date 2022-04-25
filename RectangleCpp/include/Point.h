#pragma once

#include <sstream>
#include "Object.h"

struct Point: public Object {
	double x;
	double y;

	Point();
	Point(double x, double y);

	friend std::ostream& operator<<(std::ostream &out, Point& point);
	friend std::istream& operator>>(std::istream &in, Point& point);
	friend bool operator==(Point& p1, Point& p2);

	std::string toString() override;
};
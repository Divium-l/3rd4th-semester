#pragma once

#include <sstream>
#include "Object.h"

struct Point: public Object {
	double x;
	double y;

	Point();
	Point(double x, double y);

	std::string toString() override;
};
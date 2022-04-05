#pragma once

#include <string>
#include <stdexcept>
#include "Color.h"

class Font
{
protected:
	std::string name;
	Color color;

private:
	uint8_t size;

	void throwExceptionIfIllegalSize(int size);

public:
	Font(std::string name, Color color, int size);

	void setName(std::string name);

	void setColor(Color color);

	void setSize(int size);

	std::string getName();

	Color getColor();

	int getSize();
};


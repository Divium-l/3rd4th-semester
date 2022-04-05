#include "Font.h"

#pragma region private
void Font::throwExceptionIfIllegalSize(int size) {
	if (size < 0)
		throw new std::invalid_argument("Font size cannot be < 0");
}
#pragma endregion

#pragma region public
Font::Font(std::string name, Color color, int size) {
	throwExceptionIfIllegalSize(size);
	this->name = name;
	this->color = color;
	this->size = size;
}

void Font::setName(std::string name) {
	this->name = name;
}

void Font::setColor(Color color) {
	this->color = color;
}

void Font::setSize(int size) {
	throwExceptionIfIllegalSize(size);
	this->size = size;
}

std::string Font::getName() {
	return name;
}

Color Font::getColor() {
	return color;
}

int Font::getSize() {
	return size;
}
#pragma endregion public
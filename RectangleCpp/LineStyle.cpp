#include "LineStyle.h"

#pragma region private
void LineStyle::throwExceptionIfIllegalWidth(int width) {
	if (width < 0)
		throw new std::invalid_argument("Width cannot be < 0");
}
#pragma endregion private

#pragma region public
LineStyle::LineStyle() {
	this->style = LineType::SOLID;
	this->width = 1;
	this->color = Color(Colors::BLACK);
}

LineStyle::LineStyle(LineType style, int width, Color color) {
	throwExceptionIfIllegalWidth(width);
	this->style = style;
	this->width = width;
	this->color = color;
}

void LineStyle::setStyle(LineType style) {
	this->style = style;
}

void LineStyle::setWidth(int width) {
	throwExceptionIfIllegalWidth(width);
	this->width = width;
}

void LineStyle::setColor(Color color) {
	this->color = color;
}

LineType LineStyle::getStyle() {
	return style;
}

int LineStyle::getWidth() {
	return width;
}

Color LineStyle::getColor() {
	return color;
}
#pragma endregion public

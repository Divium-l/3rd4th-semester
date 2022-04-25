#include "../include/Color.h"

#pragma region private
bool Color::isValid(int number) {
	return number >= 0 && number <= 255;
}

void Color::throwExceptionIfNotValid(int red, int green, int blue) {
	if (!(isValid(red) && isValid(green) && isValid(blue)))
		throw std::invalid_argument("One of the color values less than 0 or greater than 255");
}

void Color::throwExceptionIfNotValid(int color) {
	if (!isValid(color))
		throw std::invalid_argument("One of the color values less than 0 or greater than 255");
}
#pragma endregion private

#pragma region public
Color::Color(int red, int green, int blue) {
	setColor(red, green, blue);
}

Color::Color(Colors color) {
	switch (color) {
	case Colors::BLACK:
			setColor(0, 0, 0);
			break;
		case Colors::WHITE:
			setColor(255, 255, 255);
			break;
		case Colors::RED:
			setColor(255, 0, 0);
			break;
		case Colors::GREEN:
			setColor(0, 255, 0);
			break;
		case Colors::BLUE:
			setColor(0, 0, 255);
			break;
		default:
			break;
	}
}

Color::Color() {
	setColor(0, 0, 0);
}

int Color::getRed() {
	return red;
}

int Color::getGreen() {
	return green;
}

int Color::getBlue() {
	return blue;
}

void Color::setColor(int red, int green, int blue) {
	throwExceptionIfNotValid(red, green, blue);

	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Color::setRed(int red) {
	throwExceptionIfNotValid(red);
	this->red = red;
}

void Color::setGreen(int green) {
	throwExceptionIfNotValid(green);
	this->green = green;
}

void Color::setBlue(int blue) {
	throwExceptionIfNotValid(blue);
	this->blue = blue;
}

std::string Color::toString() {
	std::ostringstream stream;
	stream << "RGB{" << "r: " << (int) red << ", g: " << (int) green << ", b: " << (int) blue << "}";
	return stream.str();
}
#pragma endregion public

std::ostream& operator<<(std::ostream &out, Color& color) {
	out << color.toString();
	return out;
}
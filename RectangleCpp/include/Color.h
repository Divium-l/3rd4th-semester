#pragma once

#include <stdexcept>
#include <sstream>
#include "Colors.h"
#include "Object.h"

class Color: public Object {
private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    bool isValid(int number);

    void throwExceptionIfNotValid(int red, int green, int blue);

    void throwExceptionIfNotValid(int color);

public:

    Color(int red, int green, int blue);

    Color(Colors color);

    Color();

    int getRed();

    int getGreen();

    int getBlue();

    void setColor(int red, int green, int blue);

    void setRed(int red);

    void setGreen(int green);

    void setBlue(int blue);

    friend std::ostream& operator<<(std::ostream &out, Color& color);

    std::string toString() override;
};


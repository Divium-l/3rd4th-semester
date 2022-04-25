#pragma once

#include <stdexcept>
#include "Color.h"
#include "Colors.h"
#include "LineType.h"

class LineStyle {
protected:
    LineType style;
    Color color;

private:
    uint8_t width;

    void throwExceptionIfIllegalWidth(int width);

public:

    LineStyle();

    LineStyle(LineType style, int width, Color color);

    void setStyle(LineType style);

    void setWidth(int width);

    void setColor(Color color);

    LineType getStyle();

    int getWidth();

    Color getColor();
};


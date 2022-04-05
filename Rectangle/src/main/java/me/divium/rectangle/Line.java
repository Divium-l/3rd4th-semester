package me.divium.rectangle;

import static me.divium.rectangle.LineStyle.*;

public class Line {
    private LineStyle style;
    private int width;
    private Color color;

    private void throwExceptionIfIllegalWidth(int width) {
        if (width < 0)
            throw new IllegalArgumentException("Width cannot be < 0");
    }

    public Line() {
        this.style = SOLID;
        this.width = 1;
        this.color = new Color(0, 0, 0);
    }

    public Line(LineStyle style, int width, Color color) {
        throwExceptionIfIllegalWidth(width);
        this.style = style;
        this.width = width;
        this.color = color;
    }

    public void setStyle(LineStyle style) {
        this.style = style;
    }

    public void setWidth(int width) {
        throwExceptionIfIllegalWidth(width);
        this.width = width;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public LineStyle getStyle() {
        return style;
    }

    public int getWidth() {
        return width;
    }

    public Color getColor() {
        return color;
    }
}

package me.divium.rectangle;

public class Color {
    private int red;
    private int green;
    private int blue;

    private boolean isValid(int number) {
        return number >= 0 && number <= 255;
    }

    private void throwExceptionIfNotValid(int red, int green, int blue) {
        if (!(isValid(red) && isValid(green) && isValid(blue)))
            throw new IllegalArgumentException("One of the color values less than 0 or greater than 255");
    }

    private void throwExceptionIfNotValid(int color) {
        if (!isValid(color))
            throw new IllegalArgumentException("One of the color values less than 0 or greater than 255");
    }

    public Color(int red, int green, int blue) {
        setColor(red, green, blue);
    }

    public int getRed() {
        return red;
    }

    public int getGreen() {
        return green;
    }

    public int getBlue() {
        return blue;
    }

    public void setColor(int red, int green, int blue) {
        throwExceptionIfNotValid(red, green, blue);

        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    public void setRed(int red) {
        throwExceptionIfNotValid(red);
        this.red = red;
    }

    public void setGreen(int green) {
        throwExceptionIfNotValid(green);
        this.green = green;
    }

    public void setBlue(int blue) {
        throwExceptionIfNotValid(blue);
        this.blue = blue;
    }

    @Override
    public String toString() {
        return "Color{" +
                "red=" + red +
                ", green=" + green +
                ", blue=" + blue +
                '}';
    }
}

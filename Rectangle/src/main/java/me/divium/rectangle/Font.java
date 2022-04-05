package me.divium.rectangle;

public class Font {
    protected String name;
    protected Color color;
    protected int size;

    protected void throwExceptionIfIllegalSize(int size) {
        if (size < 0)
            throw new IllegalArgumentException("Font size cannot be < 0");
    }

    public Font(String name, Color color, int size) {
        throwExceptionIfIllegalSize(size);
        this.name = name;
        this.color = color;
        this.size = size;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void setSize(int size) {
        throwExceptionIfIllegalSize(size);
        this.size = size;
    }

    public String getName() {
        return name;
    }

    public Color getColor() {
        return color;
    }

    public int getSize() {
        return size;
    }
}

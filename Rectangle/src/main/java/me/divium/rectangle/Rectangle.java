package me.divium.rectangle;

public class Rectangle {
    private Point firstPoint;
    private Point secondPoint;
    private Color color;

    public Rectangle(Point firstPoint, Point secondPoint, Color color) {
        this.firstPoint = firstPoint;
        this.secondPoint = secondPoint;
        this.color = color;
    }

    public Point getFirstPoint() {
        return firstPoint;
    }

    public Point getSecondPoint() {
        return secondPoint;
    }

    public Color getColor() {
        return color;
    }

    public void setFirstPoint(Point firstPoint) {
        this.firstPoint = firstPoint;
    }

    public void setSecondPoint(Point secondPoint) {
        this.secondPoint = secondPoint;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "firstPoint=" + firstPoint +
                ", secondPoint=" + secondPoint +
                ", color=" + color +
                '}';
    }
}

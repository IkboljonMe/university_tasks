interface Shape {
    double getPerimeter();
}

abstract class Polygon {
    public void printType() {
        System.out.println("This is a polygon");
    }
}

class Triangle extends Polygon implements Shape {
    private double side1, side2, side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    @Override
    public double getPerimeter() {
        return side1 + side2 + side3;
    }
}

class Square extends Polygon implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double getPerimeter() {
        return 4 * side;
    }
}

public class Main {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[2];
        shapes[0] = new Triangle(3, 4, 5);
        shapes[1] = new Square(6);

        for (Shape shape : shapes) {
            if (shape instanceof Polygon) {
                ((Polygon) shape).printType();
            }
            System.out.println("Perimeter: " + shape.getPerimeter());
            System.out.println();
        }
    }
}

#include <iostream>
#include <cmath> // For mathematical functions like pow()

using namespace std;

#define PI 3.142 // Define the value of PI

// Abstract base class 'Shape'
class Shape
{
public:
    virtual double area() const = 0;      // Pure virtual function for area
    virtual double perimeter() const = 0; // Pure virtual function for perimeter
    virtual ~Shape() {}                   // Virtual destructor to ensure proper cleanup
};

// Derived class 'Circle'
class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r) {} // Constructor with initializer list

    // Override the area() function
    double area() const override
    {
        return PI * pow(radius, 2);
    }

    // Override the perimeter() function
    double perimeter() const override
    {
        return 2 * PI * radius;
    }
};

// Derived class 'Rectangle'
class Rectangle : public Shape
{
protected:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {} // Constructor with initializer list

    // Override the area() function
    double area() const override
    {
        return length * width;
    }

    // Override the perimeter() function
    double perimeter() const override
    {
        return 2 * (length + width);
    }
};

// Derived class 'Square', inheriting from 'Rectangle'
class Square : public Rectangle
{
public:
    Square(double s) : Rectangle(s, s) {} // Pass side length to Rectangle constructor

    // Override the area() function
    double area() const override
    {
        return length * length; // Since all sides are equal
    }

    // Override the perimeter() function
    double perimeter() const override
    {
        return 4 * length; // Perimeter of a square is 4 * side length
    }
};

// Main function to test the classes
int main()
{
    double r, l, w, s;

    cout << "Enter the radius of the circle: ";
    cin >> r;
    Circle circle(r);
    cout << "Circle area: " << circle.area() << endl;
    cout << "Circle perimeter: " << circle.perimeter() << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> l >> w;
    Rectangle rectangle(l, w);
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Rectangle perimeter: " << rectangle.perimeter() << endl;

    cout << "Enter the side of the square: ";
    cin >> s;
    Square square(s);
    cout << "Square area: " << square.area() << endl;
    cout << "Square perimeter: " << square.perimeter() << endl;

    return 0;
}

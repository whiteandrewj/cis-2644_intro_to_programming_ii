#include <iostream>

using namespace std;

double const PI = 3.14159;

class Circle {
private:
    double x, y, r;
public:
    Circle(double xCoordinate, double yCoordinate, double radius) {
        x = xCoordinate;
        y = yCoordinate;
        r = radius;
    }
    void setXCoordinate(double xCoordinate) {
        x = xCoordinate;
    }
    void setYCoordinate(double yCoordinate) {
        y = yCoordinate;
    }
    void setRadius(double radius) {
        r = radius;
    }
    double getXCoordinate() {
        return x;
    }
    double getYCoordinate() {
        return y;
    }
    double getRadius() {
        return r;
    }
    void display() {
        cout << "Circle center point: (" << getXCoordinate() << "," << getYCoordinate() << ")" << endl;
        cout << "Circle radius: " << getRadius() << endl;
    }
    double getArea() {
        return PI * r * r;
    }
    
};

int main()
{
    Circle c1(4,-3,2);
    c1.display();
    cout << "Circle area: " << c1.getArea() << endl;
    c1.setXCoordinate(33);
    c1.setYCoordinate(45);
    c1.setRadius(2.5);
    c1.display();
    cout << "Circle area: " << c1.getArea() << endl;
    return 0;
}
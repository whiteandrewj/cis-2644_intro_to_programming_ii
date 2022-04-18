#include <iostream>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }

    void display() {
        cout << "Point: (" << getX() << "," << getY() << ")" << endl;
    }

    int getX() const /*nowhere within this member function can contents uf variables be modified*/ {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }
};


int main()
{
    Point p1(12,4);
    p1.display();

    return 0;
}

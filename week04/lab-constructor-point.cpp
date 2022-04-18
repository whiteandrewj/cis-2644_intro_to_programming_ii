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
        cout << "Point: (" << x << "," << y << ")";
    }
};


int main() {
    Point p1(12,4);
    p1.display();

    return 0;
}

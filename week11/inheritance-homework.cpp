#include <iostream>

using namespace std;

class Shape {
private:
    int x, y;
public:
    Shape(int, int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void moveTo(int, int);
    void rmoveTo(int, int);
    void draw();
};

Shape::Shape(int newx, int newy) {
    setX(newx);
    setY(newy);
}
int Shape::getX() { return x; }
int Shape::getY() { return y; }
void Shape::setX(int newx) { x = newx; }
void Shape::setY(int newy ) { y = newy; }
void Shape::moveTo(int newx, int newy) {
    setX(newx);
    setY(newy);
}
void Shape::rmoveTo(int deltax, int deltay) {
    moveTo(getX() + deltax, getY() + deltay);
}
void Shape::draw() {
    cout << "Drawing a shape at: " << getX() << "," << getY() << endl;
}

class RightTriangle : public Shape {
private:
    int base, height;
public:
    RightTriangle(int, int, int, int);
    int getBase();
    int getHeight();
    void setBase(int);
    void setHeight(int);
    void draw();
};

RightTriangle::RightTriangle(int newx, int newy, int newBase, int newHeight) : Shape(newx, newy) {
    setBase(newBase);
    setHeight(newHeight);
}
int RightTriangle::getBase() { return base; }
int RightTriangle::getHeight() { return height; }
void RightTriangle::setBase(int newBase) { base = newBase; }
void RightTriangle::setHeight(int newHeight) { height = newHeight; }
void RightTriangle::draw() {
    cout << "Drawing right triangle at (" << getX() << "," << getY() << "), base: "
        << getBase() << ", height: " << getHeight() << endl;
}

int main()
{
    RightTriangle t(1,2,3,4);
    t.draw();
    t.moveTo(5,6);
    t.draw();
    t.rmoveTo(2,2);
    t.draw();
    return 0;
}


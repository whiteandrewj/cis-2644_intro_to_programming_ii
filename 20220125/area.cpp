#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

double area(int radius) { //is a value returning function
    const double PI = 3.14159;
    return PI * (radius * radius);
}


int main() {
    int radius1 = 3, radius2 = 5;
    double area1 = area(radius1); //a function call. can go anywhere an expression is expected.
    double area2 = area(radius2);

}
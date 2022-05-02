#include <iostream>

using namespace std;

int doSomething(int &x, int &y) { //increase x to 10*x, increase y to 10y, return new sum 
  int temp = x;
  x = y * 10;
  y = temp * 10;
  return x + y;
}

int doSomethingElse(int *ptr_x , int *ptr_y) { //set x to 10x, set y to 10y, return new sum
  int temp = *ptr_x;
  *ptr_x = *ptr_y * 10;
  *ptr_y = temp * 10;
  return *ptr_x + *ptr_y;
}

int main() 
{
    int x = 10;
    int y = 2;
    cout << "initial values: \t(x=" << x << ",y=" << y << ")\t initial sum: " << (x+y) << endl;
    
    int ds = doSomething(x,y);
    cout << "multiply by 10: \t(x=" << x << ",y=" << y << ")\t 1st sum: " << ds << endl;

    int *ptr_x = &x;
    int *ptr_y = &y;
    int dse = doSomethingElse(ptr_x, ptr_y);
    cout << "multiply by 10 again: \t(x=" << x << ",y=" << y << ")\t 2nd sum: " << dse << endl;

    return 0;
}
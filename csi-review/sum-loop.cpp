#include <iostream>
using namespace std;

int main() {
    int number;
    int sum;
    cout << "enter the first number to sum: ";
    cin >> number;
    while (number != -999) {
        sum += number;
        cout << "enter another number to add to the sum. enter -999 to stop: ";
        cin >> number;
    }
    cout << "total sum of all numbers entered: " << sum;
}
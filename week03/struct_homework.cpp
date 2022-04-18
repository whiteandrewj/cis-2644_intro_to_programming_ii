#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;

    Time() {
        hours = 0;
        minutes = 0;
    }

    Time(int h, int m) {
        hours = h;
        minutes = m;
    }

    Time(int h) {
        hours = h;
        minutes = 0;
    }
};

struct Counter {
    int iterationCount;
    int conversion;

    Counter(int c) {
        iterationCount = 0;
        conversion = c;
    }

    //does not make sense to add a default constructor since the conversion rate (how much are we counting up to to make a whole) should always be set when initialized.
};


int main() {

    return 0;
}
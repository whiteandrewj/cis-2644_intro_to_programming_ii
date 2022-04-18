#include <iostream>

using namespace std;

class Date {
    private:
        int year, month, day;
    public:
        Date(int y, int m, int d) {
            year = y;
            month = m;
            day = d;
        }
        Date(int y, int m) {
            year = y;
            month = m;
            day = 0;
        }
        Date() {
            year = 0;
            month = 0;
            day = 0;
        }

        void display() {
            cout << "Date: " << month << "/" << day << "/" << year << endl;
        }
};

int main() {
    Date d1(2022,2,10);
    d1.display();

    Date d2(1900,1);
    d2.display();

    Date d3;
    d3.display();

    return 0;
}
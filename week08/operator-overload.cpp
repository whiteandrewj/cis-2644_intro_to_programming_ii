#include <iostream>

using namespace std;

class Date {
private:
    int m, d, y;
public:
    Date(int, int, int);
    Date();
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void display();
    friend ostream &operator<<(ostream&, const Date&);
    friend istream &operator>>(istream&, Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);
    friend bool operator<(const Date&, const Date&);
};

Date::Date(int month, int day, int year) {
    m = month;
    d = day;
    y = year;
}
Date::Date() {
    m = 1;
    d = 1;
    y = 1970;
}
void Date::setYear(int year) { y = year; }
void Date::setMonth(int month) { m = month; }
void Date::setDay(int day) { d = day; }
int Date::getYear() const { return y; }
int Date::getMonth() const { return m; }
int Date::getDay() const { return d; }
void Date::display() {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}
ostream &operator<<(ostream &s, const Date &d) {
    s << d.m << "/" << d.d << "/" << d.y;
    return s;
}
istream &operator>>(istream &s, Date &d) {
    s >> d.m;
    s >> d.d;
    s >> d.y;
    return s;
}
bool operator==(const Date &d1, const Date &d2) {
    return ((d1.d == d2.d) && (d1.m == d2.m) && (d1.y == d2.y));
}
bool operator!=(const Date &d1, const Date &d2) {
    return !((d1.d == d2.d) && (d1.m == d2.m) && (d1.y == d2.y));
}
bool operator<(const Date &d1, const Date &d2) {
    if (d1.y < d2.y) { return true; }
    else if (d1.y == d2.y) {
        if (d1.m < d2.m) { return true; }
        else if (d1.m == d2.m) {
            if (d1.d < d2.d) { return true; }
            else { return false; }
        } else { return false; }
    } else { return false; }
}


 int main()
 {
    Date d1(3,8,2022);
    cout << "Programatically created date: ";
    cout << d1 << endl;
    cout << "Enter another space-delimeted date as \"mm dd yyyy\": ";
    Date d2;
    cin >> d2;
    cout << "Manually created date: ";
    cout << d2 << endl;
    std::cout << std::boolalpha;
    cout << "are dates equal? " << (d1 == d2) << endl;
    cout << "are dates inequal? " << (d1 != d2) << endl;
    cout << "is programatic date earlier than manually created date? " << (d1 < d2) << endl;
    return 0;
}
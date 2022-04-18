#include <iostream>

using namespace std;

class Date {
private:
    int m, d, y;
    int const daysPerMonth[12];
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
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
    friend bool operator==(const Date &, const Date &);
    friend bool operator!=(const Date &, const Date &);
    friend bool operator<(const Date  &, const Date &);
    Date& operator=(const Date &d1) {
        m = d1.m;
        d = d1.d;
        y = d1.y;
        return *this;
    }
    Date operator++() {
        if (d == daysPerMonth[m-1]) {
            d = 1;
            if (m == 12) {
                m = 1;
                ++y;
            } else {
                ++m;
            }
        } else {
            ++d;
        }
        return *this;
    }
    Date operator++(int) {
        Date temp(m, d, y);
        if (d == daysPerMonth[m-1]) {
            d = 1;
            if (m == 12) {
                m = 1;
                y++;
            } else {
                m++;
            }
        } else {
            d++;
        }
        return temp;
    }
    Date operator--() {
        if (d == 1) {
            if (m == 1) {
                m = 12;
                --y;
            } else {
                --m;
            }
            d = daysPerMonth[m-1];
        } else {
            --d;
        }
        return *this;
    }
    Date operator--(int) {
        Date temp(m, d, y);
        if (d == 1) {
            if (m == 1) {
                m = 12;
                y--;
            } else {
                m--;
            }
            d = daysPerMonth[m-1];
        } else {
            d--;
        }
        return temp;
    }
};

Date::Date(int month, int day, int year)
    : daysPerMonth{31,28,31,30,31,30,31,31,31,31,30,31}
    {
    m = month;
    d = d;
    y = year;
}
Date::Date()
    : daysPerMonth{31,28,31,30,31,30,31,31,31,31,30,31}
    {
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
    cout << "Enter a space-delimeted date as \"mm dd yyyy\": ";
    Date d1;
    cin >> d1;
    cout << "Date: ";
    cout << d1 << endl;

    //test comparison operator overloads
    /*
    cout << "Enter another space-delimeted date as \"mm dd yyyy\": ";
    Date d2;
    cin >> d2;
    cout << "Second date: ";
    cout << d2 << endl;
    std::cout << std::boolalpha;
    cout << "are dates equal? " << (d1 == d2) << endl;
    cout << "are dates inequal? " << (d1 != d2) << endl;
    cout << "is first date earlier than second date? " << (d1 < d2) << endl;
    */

    //test increment and decrement operator overloads
    Date d3;
    cout << "prefix increment and assign date...";
    d3 = ++d1;
    cout << d1 << endl;
    cout << "date set via assignment: " << d3 << endl;
    cout << "postfix increment and assign date...";
    d3 = d1++;
    cout << d1 << endl;
    cout << "date set via assignment: " << d3 << endl;

    cout << "prefix decrement and assign date...";
    d3 = --d1;
    cout << d1 << endl;
    cout << "date set via assignment: " << d3 << endl;
    cout << "postfix decrement and assign date...";
    d3 = d1--;
    cout << d1 << endl;
    cout << "date set via assignment: " << d3 << endl;
    return 0;
}
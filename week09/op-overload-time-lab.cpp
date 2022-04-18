#include <iostream>
#include <string>
using namespace std;
//use to_string() to format hour min. if statement (min < 10).

class Time {
private:
    int hr,min;
public:
    Time(int,int);
    Time();
    void setHours(int);
    void setMinutes(int);
    int getHours();
    int getMinutes();
    void display();
    friend ostream &operator<<(ostream &, const Time &); //since are friend functions, don't use scope resolution operator
    friend istream &operator>>(istream &, Time &);
    friend bool operator==(const Time &, const Time &);
    friend bool operator<(const Time &, const Time &);
    friend bool operator>(const Time &, const Time &);
    const Time operator=(const Time &tm) {
        if (this != &tm) {
            hr = tm.hr;
            min = tm.min;
        }
        return *this;
    }
    Time operator++() { //prefix
        if (min == 59) {
            min = 0;
            if (hr == 23) {
                hr = 0;
            } else { 
                hr++;
            }
        } else {
            min++;
        }
        return *this;
    } 
    Time operator++(int) { //postfix
        Time temp(hr, min);
        if (min == 59) {
            min = 0;
            if (hr == 23) {
                hr = 0;
            } else { 
                hr++;
            }
        } else {
            min++;
        }
        return temp;
    }
    Time operator--() { //prefix
        if (min == 0) {
            min = 59;
            if (hr == 0) {
                hr = 23;
            } else {
                hr--;
            }
        } else {
            min--;
        }
        return *this;
    }
    Time operator--(int) { //postfix
        Time temp(hr, min);
                if (min == 0) {
            min = 59;
            if (hr == 0) {
                hr = 23;
            } else {
                hr--;
            }
        } else {
            min--;
        }
        return temp;
    }
};

Time::Time(int hours, int minutes) {
    hr = hours;
    min = minutes;
}
Time::Time() {
    hr = 0;
    min = 0;
}
void Time::setHours(int hours) { hr = hours; }
void Time::setMinutes(int minutes) { min = minutes; }
int Time::getHours() { return hr; }
int Time::getMinutes() { return min; }
void Time::display() { cout << hr << ":" << min; }
ostream &operator<<(ostream &strm, const Time &tm) {
    string minutes = to_string(tm.min);
    string hours = to_string(tm.hr);
    if (minutes.length() < 2) {
        minutes.insert(0,"0");
    }
    if (hours.length() < 2) {
        hours.insert(0,"0");
    }
    strm << hours << ":" << minutes;
    return strm;
}
istream &operator>>(istream &strm, Time &tm) {
    strm >> tm.hr;
    strm >> tm.min;
    return strm;
}
bool operator==(const Time &t1, const Time &t2) {
    return ((t1.hr == t2.hr) && (t1.min == t2.min)); 
}
bool operator<(const Time &t1, const Time &t2) {
    if (t1.hr < t2.hr) { return true; }
    else if (t1.hr == t2.hr) {
        if (t1.min < t2.min) { return true; }
        else {return false; }
    } else { return false; }
}
bool operator>(const Time &t1, const Time &t2) {
    if (t1.hr > t2.hr) { return true; }
    else if (t1.hr == t2.hr) {
        if (t1.min > t2.min) { return true; }
        else {return false; }
    } else { return false; }
}

int main()
{
    Time t1;
    cout << "enter a time as \"hh mm\" (space separated): ";
    cin >> t1;
    cout << t1 << endl;
    Time t2;
    cout << "enter another time as \"hh mm\" (space separated): ";
    cin >> t2;
    cout << t2 << endl;
    std::cout << std::boolalpha;
    cout << "is first time equal to second? " << (t1 == t2) << endl;
    cout << "is first time less than the second? " << (t1 < t2) << endl; 
    cout << "is first time greater than the second? " << (t1 > t2) << endl;

    Time t3;
    t3 = t1;
    cout << "test assignment operator. This should be same as first time..." << t3 << endl;

    Time t4;
    cout << "prefix increment first time and assign to new time ...";
    t4 = ++t1;
    cout << t1 << endl;
    cout << "time set via assignment: " << t4 << endl;
    cout << "postfix increment first time and assign to new time...";
    t4 = t1++;
    cout << t1 << endl;
    cout << "time set via assignment: " << t4 << endl;

    cout << "prefix decrement first time and assign to new time...";
    t4 = --t1;
    cout << t1 << endl;
    cout << "time set via assignment: " << t4 << endl;
    cout << "postfix decrement first time and assign to new time...";
    t4 = t1--;
    cout << t1 << endl;
    cout << "time set via assignment: " << t4 << endl;

    return 0;
}

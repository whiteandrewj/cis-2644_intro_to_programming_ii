#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Employee {
private:
    string nm;
    int id;
    //tm hrdt;
    string hrdt;
public:
    Employee();
    Employee(string, int, string);
    string getName();
    int getId();
    //tm getHireDate();
    string getHireDate();
    void setName(string);
    void setId(int);
    void setHireDate(string);
};

string Employee::getName() { return nm; }
int Employee::getId() { return id; }
//tm Employee::getHireDate() { return hrdt; }
string Employee::getHireDate() { return hrdt; }
void Employee::setName(string name) { nm = name; }
void Employee::setId(int idNumber) { id = idNumber; }
void Employee::setHireDate(string hireDate) {
    hrdt = hireDate;
    /*
    hrdt.tm_mon = stoi(hireDate.substr(0,2))-1;
    hrdt.tm_mday = stoi(hireDate.substr(3,2));
    hrdt.tm_year = stoi(hireDate.substr(5,4))-1900;
    hrdt.tm_isdst = -1;
    hrdt.tm_hour = 0;
    hrdt.tm_min = 0;
    hrdt.tm_sec = 0;
    */
}

Employee::Employee() {
    setName("");
    setId(0);
    setHireDate("01/01/1900");
}
Employee::Employee(string name, int idNumber, string hireDate) {
    setName(name);
    setId(idNumber);
    setHireDate(hireDate);
}



int main()
{
    Employee e1("Andew White",12345,"08/12/2018");
    cout << e1.getName() << endl;
    cout << e1.getId() << endl;
    //cout << mktime(&e1.getHireDate()) << endl;
    cout << e1.getHireDate() << endl;
    return 0;
}
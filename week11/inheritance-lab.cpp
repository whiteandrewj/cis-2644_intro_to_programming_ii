#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Employee {
private:
    string nm;
    int id;
    tm hrdt;
public:
    Employee();
    Employee(string, int, string);
    string getName();
    int getId();
    tm getHireDate();
    void setName(string);
    void setId(int);
    void setHireDate(string);
};

class ProductionWorker : public Employee {
private:
    int sft;
    double hryRt;
public:
    int getShift();
    double getHourlyRate();
    void setShift(int);
    void setHourlyRate(double);
    ProductionWorker(string, int, string);
    ProductionWorker(string, int, string, int, double);
};

string Employee::getName() { return nm; }
int Employee::getId() { return id; }
tm Employee::getHireDate() { return hrdt; }
void Employee::setName(string name) { nm = name; }
void Employee::setId(int idNumber) { id = idNumber; }
void Employee::setHireDate(string hireDate) {
    hrdt.tm_mon = stoi(hireDate.substr(0,2))-1; //months since Jan
    hrdt.tm_mday = stoi(hireDate.substr(3,2)); //day of month
    hrdt.tm_year = stoi(hireDate.substr(6,4))-1900; //years since 1900
    hrdt.tm_isdst = -1;
    hrdt.tm_hour = 0;
    hrdt.tm_min = 0;
    hrdt.tm_sec = 0;
}
Employee::Employee() {
    setName("");
    setId(0);
    setHireDate("01/01/1970");
}
Employee::Employee(string name, int idNumber, string hireDate) {
    setName(name);
    setId(idNumber);
    setHireDate(hireDate);
}
int ProductionWorker::getShift() { return sft; }
double ProductionWorker::getHourlyRate() { return hryRt; }
void ProductionWorker::setShift(int shift) { sft = shift; }
void ProductionWorker::setHourlyRate(double hourlyRate) { hryRt = hourlyRate; }
ProductionWorker::ProductionWorker(string name, int idNumber, 
        string hireDate) : Employee(name, idNumber, hireDate)
    {
    setShift(0);
    setHourlyRate(0.0);
}
ProductionWorker::ProductionWorker(string name, int idNumber, string hireDate, 
        int shift, double hourlyRate) : Employee(name, idNumber, hireDate)
    {
    setShift(shift);
    setHourlyRate(hourlyRate);
}


int main()
{
    Employee e1("Andew White",12345,"08/12/2018");
    cout << "Name: " << e1.getName() << endl;
    cout << "ID Number: " <<e1.getId() << endl;
    time_t tmptm1 = mktime(&e1.getHireDate());
    cout << "Hire Date: " << ctime(&tmptm1);

    cout << "---------------------------------------------------" << endl;

    ProductionWorker p1("Andres Blanco",54321,"04/01/2022");
    cout << "Name: " << p1.getName() << endl;
    cout << "ID Number: " << p1.getId() << endl;
    time_t tmptm2 = mktime(&p1.getHireDate());
    cout << "Hire Date: " << ctime(&tmptm2); 
    cout << "Shift #: " << p1.getShift() << endl;
    cout << "Hourly Rate $: " << p1.getHourlyRate() << endl;

    cout << "---------------------------------------------------" << endl;

    ProductionWorker p2("Andre Blanc",22222,"12/31/2099",2,3500.50);
    cout << "Name: " << p2.getName() << endl;
    cout << "ID Number: " << p2.getId() << endl;
    time_t tmptm3 = mktime(&p2.getHireDate());
    cout << "Hire Date: " << ctime(&tmptm3); 
    cout << "Shift #: " << p2.getShift() << endl;
    cout << "Hourly Rate: $" << p2.getHourlyRate() << endl;




    return 0;
}
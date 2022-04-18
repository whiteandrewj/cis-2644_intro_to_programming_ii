#include <iostream>

using namespace std;

class Student {
private:
    //member variables
    string name;
    int age;

    int setAge(int a) { //example of data validation helper function
        if (a >= 0 && a <= 120) {
            return a;
        }
        return 0;
    }

public:
    Student(string n, int a) {
        name = n;
        age = setAge(a);
    }
    Student() {
        name = "";
        age = 0;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    bool equals(Student s) {
        if (name == s.name && 
            age == s.age) {
                return true;
            }
        return false;
    }
};

int main() {
    Student s1("Jane Doe", 23); //instantiation
    Student s2; //calling the default constructor. in cpp, if no constructor is defined will automagically assign default variable values
    s1.display();

    return 0;
}
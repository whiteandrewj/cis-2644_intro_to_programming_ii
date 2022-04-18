#include <iostream>
using namespace std;

struct Student { //make name of struct capitalized. struct is declared in global space
    string name; //body of struct is where fields are declared
    int grade;

    void display(Student s) {
        cout << "Name: " << s.name << endl;
        cout << "Grade :" << s.grade << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Jane Doe";
    s1.grade = 99;
    //Student s2 = ("Mary Smith", 88);

    //can do assignment aggregately
    Student s3 = s1;

    Student students[3];

    //can access array of structs via range for loop
    for (Student s : students) {
        s.display(s);
    }

    return 0;
}
#include <iostream>
using namespace std;

struct Student {
    string name;
    int grade;
};

bool sameStudent(Student s1, Student s2) {
    if (s1.name == s2.name && s1.grade == s2.grade) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Student s1;
    s1.name = "Jane Doe";
    s1.grade = 93;
    Student s2;
    s2.name = "James Smith";
    s2.grade = 87;
    Student students[2];
    students[1] = s1;
    students[2] = s2;
    
}

//some operations can be done on structs aggregately, while others cannot.
//e.g. comparison cannot be done, would need a function
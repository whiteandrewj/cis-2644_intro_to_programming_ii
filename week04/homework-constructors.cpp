#include <iostream>
using namespace std;

class Name {
    private:
        string firstName, middleName, lastName;
    
    public:
        Name(string f, string m, string l) {
            firstName = f;
            middleName = m;
            lastName = l;
        }
        
        Name(string f, string l) {
            firstName = f;
            middleName = "";
            lastName = l;
        }

        Name(string l) {
            firstName = "";
            middleName = "";
            lastName = l;
        }

        Name() {
            firstName = "";
            middleName = "";
            lastName = "";
        }

};

int main() {

    Name n1("Paul", "James", "McCartney");
    Name n2("Paul", "McCartney");
    Name n3("McCartney");

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string id;
    double balance;
    string getBalanceFormatted() {
        string s = to_string(balance);
        return s.substr(0, s.find(".") + 3);
    }
public:
    Account(string idNumber, double initialBalance) {
        id = idNumber;
        balance = initialBalance;
    }
    double getBalance() {
        return balance;
    }
    string getIdNumber() {
        return id;
    }
    void debitOrCredit(double transactionAmount) {
        balance += transactionAmount;
    } 
    void display() {
        cout << "Account Number " << getIdNumber() << endl << "Balance $" << getBalanceFormatted() << endl;
    }
};

int main()
{
    Account newAccount("0012345",100.00);
    newAccount.display();
    newAccount.debitOrCredit(-5.50);
    newAccount.display();
    newAccount.debitOrCredit(100.25);
    newAccount.display();
    return 0;
}

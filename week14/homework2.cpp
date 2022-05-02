#include <iostream>
#include <ctime>
#include <set>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
    srand(time(0));
    set<int> nums;

    for (int i = 0; i < 200; i++) {
        nums.insert(rand() % 10000 +1 );
    }
    cout << "even numbers in the set: " << endl;
    for_each(nums.begin(),nums.end(),[](int n){ if((n % 2) == 0) {cout << n << " ";} });
    cout << endl;

    map<string,string> contacts;
    string proceed = "y";
    string name;
    string number;
    cout << "Please enter names and mobile numbers to populate a contact list." << endl;
    while(proceed == "y") {
        cout << "Name: ";
        cin >> name;
        cout << "Phone Number: ";
        cin >> number;
        contacts.insert({name,number});
        cout << "Contacts entry: (" << name << "," << contacts[name] << ")" << endl;
        cout << "Enter another? (y/n): ";
        cin >> proceed;
    }    



    return 0;
}
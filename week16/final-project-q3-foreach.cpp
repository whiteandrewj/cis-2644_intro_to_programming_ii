#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    //if(n == 2) { return true; }
    for(int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void displayIfPrime(int n) {
    if (isPrime(n)) { cout << n << " "; }
}

int main()
{
    int num = 0;
    do {
        cout << "Please enter a positive integer greater than 1: ";
        cin >> num;
        if (num < 2) { cout << "Number does not fall within specified range." << endl
        ; }
    } while (num < 2);

    vector<int> nums;
    for(int i = 2; i <= num; i++) {
        nums.push_back(i);
    }

    for_each(nums.begin(),nums.end(),displayIfPrime);
    cout << endl;

    return 0;
}
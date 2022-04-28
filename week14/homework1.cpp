#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> nums;
    for (int i = 0; i < 100; i++) {
        nums.push_back(rand() % 100 + 1);
    }
    sort(nums.begin(), nums.end());
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
    int oddCount = count_if(nums.begin(), nums.end(), [](int n) { return ((n % 2)==1); });
    cout << "number of odd elements: " << oddCount << endl;

    int evenCount = count_if(nums.begin(), nums.end(), [](int n) { return ((n % 2)==0); });
    cout << "number of even elements: " << evenCount << endl;

    cout << "print if less than 30: ";
    auto print_lt35 = [](int n) { if (n < 35) { cout << n << " "; } };
    print_lt35(20);
    print_lt35(35);
    print_lt35(50);
    print_lt35(-4);
    cout << endl;

    cout << "numbers in vector greater than 50: "; 
    for_each(nums.begin(), nums.end(), [](int n) { if (n > 50) { cout << n << " "; } });

    return 0;
}
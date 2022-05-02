#include <iostream>
#include <ctime>

using namespace std;

int mostCommon(int arraySize, int array[]) {
    int maxFreqElement = 0;
    int maxFreqCount = 0;
    int cnt, element;

    //cout << "element\tcnt" << endl << "-------------" << endl;

    for (int i = 0; i < arraySize; i++) {
        element = *(array + i);
        cnt = 0;

        for (int j = 0; j < arraySize; j++) {
            if (*(array + i) == *(array + j)) {
                cnt++;
            }
        }

        //cout << element << "\t" << cnt << endl;
        
        if (cnt > maxFreqCount) {
            maxFreqCount = cnt;
            maxFreqElement = element;
        }
    }

    if (maxFreqCount == 1) {
        return -1;
    } else {
        return maxFreqElement;
    }
}

int main()
{
    srand(time(0));
    const int ARRAY_SIZE = 100;
    int nums[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        nums[i] = (rand() % 100) + 1; 
    }

    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Most common array element: " << mostCommon(ARRAY_SIZE, nums) << endl;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    const int SZ = 10;
    int numbers[SZ];
    for (int i = 0; i < SZ; i++) {
        numbers[i] = rand() % 100;
    }
}
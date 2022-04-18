#include <iostream>
using namespace std;

int main() {
    int score;
    string letterGrade;
    
    cout << "please enter a numeric test score between 90 and 100\n:";
    cin >> score;
    if (score < 90 | score > 100) {
        cout << "invalid. score not in required range";
        return 1;
    } else if (score <= 92) {
        letterGrade = "A-";
    } else if (score <= 97) {
        letterGrade = "A";
    } else {
        letterGrade = "A+";
    }
    
    cout << "test score: " << score << "\nletter grade: " << letterGrade;

    return 0;
}
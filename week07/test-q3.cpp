#include <iostream>

using namespace std;

class TestScores {
private:
    double testOne, testTwo, testFinal;
public:
    TestScores(double unitOneTest, double unitTwoTest, double finalTest) {
        testOne = unitOneTest;
        testTwo = unitTwoTest;
        testFinal = finalTest;
    }
    TestScores() {
        testOne = 0;
        testTwo = 0;
        testFinal = 0;
    }
    void setUnitOneTest(double unitOneTest) {
        testOne = unitOneTest;
    }
    void setUnitTwoTest(double unitTwoTest) {
        testTwo = unitTwoTest;
    }
    void setFinalTest(double finalTest) {
        testFinal = finalTest;
    }
    double getUnitOneTest() {
        return testOne;
    }
    double getUnitTwoTest() {
        return testTwo;
    }
    double getFinalTest() {
        return testFinal;
    }
    void display() {
        cout << "test 1: " << getUnitOneTest() << ", test 2: " << getUnitTwoTest() << ", final test: " << getFinalTest() << endl;
    }
    double getAverage() {
        return (getUnitOneTest() + getUnitTwoTest() + getFinalTest()) / 3;
    }
};

int main()
{
    TestScores t1(90,80,75.5);
    t1.display();
    cout << "Average Score: " << t1.getAverage() << endl;

    TestScores t2;
    t2.setUnitOneTest(70);
    t2.setUnitTwoTest(80);
    t2.setFinalTest(75);
    t2.display();
    cout << "Average Score: " << t2.getAverage() << endl;
    return 0;
}
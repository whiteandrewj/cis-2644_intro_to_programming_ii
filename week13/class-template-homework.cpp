#include <iostream>
#include <type_traits>

using namespace std;

template <typename T1, typename T2>
class Average {
private:
    T1 num1;
    T2 num2;
public:
    Average(T1, T2);
    auto compute();
};

template <typename T1, typename T2>
Average<T1,T2>::Average(T1 n1, T2 n2) {
    num1 = n1;
    num2 = n2;
}

template <typename T1, typename T2>
auto Average<T1,T2>::compute() {
    return (num1+num2)/2.0;
}

int main()
{
    Average<int,int> a1(5,4);
    cout << "average of 5 and 4: " << a1.compute() << endl;

    Average<double,double> a2(2.5,5);
    cout << "average of 2.5 and 5: " << a2.compute() << endl;

    Average<int,double> a3(4,5.75);
    cout << "average of 4 and 5.75: " << a3.compute() << endl;


    return 0;
}

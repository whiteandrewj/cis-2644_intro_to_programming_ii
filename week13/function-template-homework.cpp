#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
T absoluteValue(T num) {
    if (num < 0) {
        return num-(num*2); 
    } else {
        return num;
    }
}

template <typename T1, typename T2>
typename common_type<T1,T2>::type maximum(T1 val1, T2 val2) {
    return val1 < val2 ? val2 : val1;
}
template <typename T1, typename T2>
typename common_type<T1,T2>::type minimum(T1 val1, T2 val2) {
    return val1 > val2 ? val2 : val1;
}

int main()
{
    cout << "absolute val of 5: " << absoluteValue(5) << endl; 
    cout << "absolute val of -5: " << absoluteValue(-5) << endl; 
    cout << "absolute val of 3.3: " << absoluteValue(3.3) << endl;
    cout << "absolute val of -3.3: " << absoluteValue(-3.3) << endl;

    cout << "maximum of 3.3 and 5: " << maximum(3.3,5) << endl;
    cout << "maximum of 3.3 and -5: " << maximum(3.3,-5) << endl;

    cout << "minimum of 3.3 and 5: " << minimum(3.3,5) << endl;
    cout << "minimum of 3.3 and -5: " << minimum(3.3,-5) << endl;


    return 0;
}
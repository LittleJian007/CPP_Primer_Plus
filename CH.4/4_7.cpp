#include <iostream>
int main()
{
    using namespace std;
    int a = 1;
    double b = 3.2;
    float c = 3;
    float *p_c, d;
    p_c = &c;
    cout << "a addrss:" << &a << endl;
    cout << "b addrss:" << &b << endl;
    cout << "c addrss:" << &c << endl;
    cout << "c addrss:" << p_c << endl;

    cout << "c value:" << c << endl;
    cout << "c value:" << *p_c << endl;

    *p_c =*p_c + 1;
    cout << "c value:" << c << endl;
    return 0;
}
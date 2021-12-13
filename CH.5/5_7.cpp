#include <iostream>
int main ()
{
    using namespace std;
    double number[5]={21.1,32.8,23.4,45.2,37.4};
    double *pt = number;
    cout << "++*pt = " << ++*pt << endl;
    cout << "*++pt = " << *++pt << endl;
    cout << "*pt++ = " << *pt++ << endl;
    cout << "(*pt)++ = " << (*pt)++ << endl;

    return 0;
}
#include <iostream>
int main()
{
    using namespace std;
    int *pt = new int;
    *pt = 12;

    cout << "pt: " << pt <<endl;
    cout << "pt: " << pt[0] << endl;

    cout << "*pt: " << *pt <<endl;
    cout << "pt adress: " << &pt <<endl;

    cout << "size of pt: " << sizeof(pt) << endl;
    cout << "size of *pt: " << sizeof(*pt) << endl;

    delete pt;
    system("pause");
    return 0;
}
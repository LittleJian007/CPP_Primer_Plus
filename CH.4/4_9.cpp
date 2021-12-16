#include <iostream>
int main()
{
    using namespace std;
    int *pd = new int [3];
    pd[0] = 1;
    pd[1] = 2;
    pd[2] = 3;

    cout << pd[0] << endl;
    cout << pd[1] << endl;
    cout << pd[2] << endl;
    // cout << INT_MIN <<endl;

    pd += 1;
    cout << pd[0] << endl;
    cout << pd[1] << endl;
    cout << pd[2] << endl;

    pd -= 1;
    cout << pd[0] << endl;
    cout << pd[1] << endl;
    cout << pd[2] << endl;
    cout << *pd << endl;

    system("pause");
    return 0;
}
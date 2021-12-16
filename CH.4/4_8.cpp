
#include <iostream>
using namespace std;
int main()
{
    int *pt = new int;
    double *pd = new double;
    *pt = 1000;
    *pd = 1002.02;
    cout << *pd << *pt << endl;
    return 0;
}
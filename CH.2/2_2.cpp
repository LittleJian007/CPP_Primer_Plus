#include <iostream>
#include <math.h>
int sum1(int i, int j, int k);
int main()
{
    using namespace std;
    cout << sqrt(0.4)<< endl;
    cout << sum1(5, 6, 7) << endl;
    // printf("25");
    // printf(25);
    cin.get();
    return 0;
}
int sum1(int i, int j, int k)
{
    return i + j + k;
}

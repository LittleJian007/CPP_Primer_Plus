#include <iostream>
int main ()
{
    using namespace std;
    int by;
    cin >> by;
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    return 0;
}
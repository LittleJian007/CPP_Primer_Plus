#include <iostream>
using namespace std;
void cout_1(int n);

int main()
{
    int size = 0;
    cin >> size;
    cout_1(size);
    // cin.get();
    // cin.get();
    return 0;
}

void cout_1(int n)
{
    for (int i = 1; i <= n; i++)
        cout << " C++! " << i << endl;
    return;
}

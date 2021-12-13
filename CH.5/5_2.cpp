#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter The starting countdown value:";
    int limit, i;
    cin >> limit;
    for (i = limit; i; i--)
        cout << "i=" << i << endl;
    cout << "Done now that i = " << i << endl;

    return 0;
}
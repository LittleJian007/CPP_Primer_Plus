#include <iostream>
#include <climits>
int main()
{
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof(short) << " bytes." << endl;
    cout << "int is " << sizeof n_long << " bytes." << endl;
    cout << "int is " << sizeof n_llong << " bytes." << endl;

    cout << "MAXimum values:" << endl;
    cout << "int :" << n_int << endl;
    cout << "short :" << n_short << endl;
    cout << "long :" << n_long << endl;
    cout << "long long :" << n_llong << endl;

    cout << "Minimum int value:  " << INT_MIN << endl;
    cout << "Bite per byte :" << CHAR_BIT << endl;

    int a(5);
    int b{};
    short c{};
    short d;
    double e = 12e12;
    int f = 12.5/2;
    cout << a << b << c << d << e << f << endl;

    // cin.get();
    return 0;
}
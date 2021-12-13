
#include <iostream>
using namespace std;
int main()
{

    enum color{red,yellow,blue};
    color bit ;
    bit = color(3);
    cout << bit << endl;
    bit = blue;
    cout << bit << endl;

    return 0;
}
#include <iostream>
#include "time0.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    Time diff;
    Time abj;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding time = ";
    total.Show();
    cout << endl;

    diff = fixing - coding;
    diff.Show();
    cout << endl;

    abj = coding * 1.5;
    abj.Show();
    cout << endl;


    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+ (total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;


    return 0; 
}
    
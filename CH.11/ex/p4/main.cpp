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
    //planning.Show();
    cout << fixing;

    cout << "coding time = ";
    //coding.Show();
    cout << coding;

    cout << "fixing time = ";
    //fixing.Show();
    cout << fixing;

    total = coding + fixing;
    cout << "coding time = ";
    //total.Show();
    cout << total;

    diff = fixing - coding;
    //diff.Show();
    cout << diff;

    abj = coding * 1.5;
    //abj.Show();
    cout << abj;

    abj = 1.5 * coding;
    //abj.Show();
    cout << abj;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    //morefixing.Show();
    cout << morefixing;

    total = morefixing + total;
    cout << "morefixing.operator+(total) = ";
    //total.Show();
    cout << total;


    return 0; 
}
    
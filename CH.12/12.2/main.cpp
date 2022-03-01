#include <iostream>
#include "StringBad.h"

void callme1(StringBad &rst);
void callme2(StringBad st);

int main()
{
    StringBad headline1("Hello world");
    StringBad headline2("Good moring");
    StringBad sports("Hello python");

    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;

    callme1(headline1);
    callme2(headline2);

    return 0;
}

void callme1(StringBad &rst)
{
    cout << "引用字符串：" << rst << endl;
}

void callme2(StringBad st)
{
    cout << "传递字符串：" << st << endl;
}
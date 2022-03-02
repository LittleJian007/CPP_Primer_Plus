#include <iostream>
#include "StringBad.h"

void callme1(StringBad &rsb);
void callme2(StringBad st);

int main()
{
    StringBad headline1("Hello world"); //用户构造函数调用
    StringBad headline2("Good moring");
    StringBad sports("Hello python");
    StringBad cpp; //用户定义的默认构造函数调用

    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    cout << "CPP: " << cpp << endl;

    callme1(headline1);
    callme2(headline2);

    return 0;
}

void callme1(StringBad &rsb)
{
    cout << "通过引用传递的字符串:" << rsb << endl;
}

void callme2(StringBad sb)
{
    cout << "通过值传递的字符串：" << sb << endl;
}
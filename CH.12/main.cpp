#include "Stringbad.h"
#include <iostream>
using std::cout;
using std::endl;

void callme1(const StringBad &rsb);
void callme2(const StringBad sb);


int main()
{
    StringBad headline1("hello world");
    StringBad headline2("Good morning");
    StringBad sports("I love you, Rick.");

    cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports: " << sports << endl;

    callme1(headline1);
    callme2(headline2);

    return 0;
}

void callme1(const StringBad &rsb)
{
    cout << "通过引用传递的字符串:" << rsb << endl;
}

void callme2(const StringBad sb)
{
    cout << "通过值传递的字符串：" << sb << endl;
}
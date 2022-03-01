#ifndef _STRINGBAD_H
#define _STRINGBAD_H

#include <iostream>
using namespace std;

class StringBad
{
private:
    char *str;
    int len;
    static int num_strings;

public:
    StringBad(const char *s); //自定义构造函数
    StringBad();              //默认构造函数
    ~StringBad();             //析构函数
    friend ostream &operator<<(ostream &os, const StringBad &st);
};

#endif

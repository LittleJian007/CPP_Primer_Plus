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
    StringBad(const char *s);       //自定义构造函数
    StringBad();                    //默认构造函数
    StringBad(const StringBad &st); //用户创建赋值对象
    ~StringBad();                   //析构函数

    StringBad &operator=(const StringBad &st);               //对象赋值         (为什么没有用friend ？？)
    friend ostream &operator<<(ostream &os, const StringBad &st); //<<字符重载
};

#endif

#ifndef _STRNG_H
#define _STRNG_H

#include <iostream>
using namespace std;

class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    String(const char *s);             //自定义构造函数
    String();                          //默认构造函数
    String(const String &st);          //用户创建赋值对象
    ~String();                         //析构函数
    int length() const { return len; } //内联函数

    String &operator=(const String &st); //对象赋值         (为什么没有用friend ？？)
    String &operator=(const char *s);
    char &operator[](int i);
    const char &operator[](int i) const;

    // 运算符重载
    friend bool operator<(const String &str1, const String &str2);
    friend bool operator>(const String &str1, const String &str2);
    friend bool operator==(const String &str1, const String &str2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);

    static int HowMany();

    friend String operator+(const char *s, const String &st);
    String operator+(const String &st);
    void stringlow();
    void stringup();
    int has(char ch) const;
};

#endif

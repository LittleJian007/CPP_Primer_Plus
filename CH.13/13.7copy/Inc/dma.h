#ifndef DMA_H
#define DMA_H

#include <iostream>

using namespace std;

class baseDMA
{
private:
    char *lable;
    int rating;

public:
    baseDMA(const char *l = "null", int r = 0);                 //默认构造函数
    baseDMA(const baseDMA &bs);                                 //复制构造函数
    virtual ~baseDMA();                                         //析构函数
    baseDMA &operator=(const baseDMA &bs);                      //赋值构造函数或 =运算符重载
    friend ostream &operator<<(ostream &os, const baseDMA &bs); // <<运算符重载
};

class lacksDMA : public baseDMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

public:
    lacksDMA(const char *l = "null", int r = 0, const char *c = "blank");
    lacksDMA(const baseDMA &bs, const char *c = "blank");
    friend ostream &operator<<(ostream &os, const lacksDMA &ls);
};

class hasDMA : public baseDMA
{
private:
    char *style;

public:
    hasDMA(const char *l = "null", int r = 0, const char *s = "null");
    hasDMA(const baseDMA &bs, const char *s);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &hs);
    friend ostream &operator<<(ostream &os, const hasDMA &hs);
};

#endif
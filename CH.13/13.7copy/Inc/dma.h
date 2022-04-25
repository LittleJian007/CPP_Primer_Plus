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
    baseDMA(const char *l = "null", int r = 0);                //默认构造函数
    baseDMA(const baseDMA &bs);                                //复制构造函数
    virtual ~baseDMA();                                        //析构函数
    baseDMA &operator=(const baseDMA &bs);                     //复制构造函数或 =运算符重载
    friend ostream &operator<<(ostream &os, baseDMA &baseDMA); // <<运算符重载
};



#endif
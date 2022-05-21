#include "dma.h"
#include <cstring>

//默认构造函数
baseDMA::baseDMA(const char *l, int r)
{
    lable = new char[strlen(l) + 1];
    strcpy(lable, l);
    rating = r;
}

//复制函数
baseDMA::baseDMA(const baseDMA &bs)
{
    lable = new char[strlen(bs.lable) + 1];
    strcpy(lable, bs.lable);
    rating = bs.rating;
}

//析构函数
baseDMA::~baseDMA()
{
    delete[] lable;
    cout << "调用基类析构函数" << endl;
}

//= 运算符重载或赋值函数
baseDMA &baseDMA::operator=(const baseDMA &bs)
{
    if (this == &bs)
        return *this;
    delete[] lable;
    lable = new char[strlen(bs.lable) + 1];
    strcpy(lable, bs.lable);
    rating = bs.rating;
    return *this;
}

// << 运算符重载
ostream &operator<<(ostream &os, const baseDMA &bs)
{
    os << "Lable: " << bs.lable << endl;
    os << "Rating: " << bs.rating << endl;
    return os;
}

//默认构造函数
lacksDMA::lacksDMA(const char *l, int r, const char *c) : baseDMA(l, r)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

//将基类做参数，构造函数
lacksDMA::lacksDMA(const baseDMA &bs, const char *c) : baseDMA(bs)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

// << 运算符重载
ostream &operator<<(ostream &os, const lacksDMA &ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << endl;
    return os;
}

//默认构造函数
hasDMA::hasDMA(const char *l, int r, const char *s) : baseDMA(l, r)
{
    style = new char[strlen(s) + 1]; //什么时候用new，什么时候用字符串拷贝函数
    strcpy(style, s);
}

hasDMA::hasDMA(const baseDMA &bs, const char *s) : baseDMA(bs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::~hasDMA()
{
    delete[] style;
    // cout << "调用析构函数" << endl;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs); // this = hs;运算符重载表示方法：函数表示法、运算符表示法
    delete[] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

ostream &operator<<(ostream &os, const hasDMA &hs)
{
    os << (const baseDMA &)hs;
    os << "Style: " << hs.style << endl;
    return os;
}
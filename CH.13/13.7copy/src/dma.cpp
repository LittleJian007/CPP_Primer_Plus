#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r)
{
    lable = new char[strlen(l) + 1];
    strcpy(lable, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &bs)
{
    lable = new char[strlen(bs.lable) + 1];
    strcpy(lable, bs.lable);
    rating = bs.rating;
}

baseDMA::~baseDMA()
{
    delete []lable;
}

baseDMA &baseDMA::operator=(const baseDMA &bs)
{
    if(this == &bs)
        return *this;
    delete []lable;
    lable = new char[strlen(bs.lable) + 1];
    strcpy(lable, bs.lable);
    rating = bs.rating;
    return *this;
}

ostream &operator<<(ostream &os, baseDMA &bs)
{
    os << "Lable: " << bs.lable << endl;
    os << "Rating: " << bs.rating << endl;
    return os;
}



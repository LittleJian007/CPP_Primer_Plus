#include "stonewt.h"
#include <iostream>
using std::cout;
using std::endl;

Stonewt::Stonewt(double lbs)
{
    stone = (int) lbs / Lbs_per_stn;
    pds_left = (int) lbs % Lbs_per_stn + lbs - (int) lbs;
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    pounds = stone = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_stn() const
{
    cout << stone << " 英石，" << pds_left << " 磅。" << endl;
}

void Stonewt::show_lbs() const
{
    cout << pounds << "磅" << endl;
}

int Stonewt::stone_to_int() const 
{
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}
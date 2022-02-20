#ifndef STONEWT_H_
#define STONEWT_H_


class Stonewt
{
private:

    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;

public:

    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    //转换函数
    // operactor int () const;  //隐式转换，变为显式类型转换可用explicit
    int stone_to_int() const;   //另一种显示转换
    operator double() const;


};

#endif
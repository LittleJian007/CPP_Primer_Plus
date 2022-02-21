#ifndef TIME0_H_
#define TIME0_H_
#include <iostream>
using namespace std;
class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        // Time Sum(const Time &t) const;
        //运算符重载
        // Time operator+(const Time & t) const;
        // Time operator-(const Time & t) const;
        // Time operator*(double mlt) const;
        friend Time operator+(const Time &s, const Time &t);
        friend Time operator-(const Time &s, const Time &t);
        friend Time operator*(const Time &s,double mult);

        friend Time operator*(double mult, const Time &t);
        friend ostream &operator<<(ostream &os, const Time &t);
        //void Show() const;
};

#endif
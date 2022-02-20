#include "time0.h"
#include <iostream>

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int a,b;
    a = hours * 60 + minutes;
    b = t.hours * 60 + t.minutes;
    diff.hours = (a - b) / 60;
    diff.minutes = (a - b) % 60;
    return diff;
}

Time Time::operator*(double mlt) const
{
    Time result;
    long temp = hours * 60 * mlt + minutes * mlt;
    result.hours = temp / 60;
    result.minutes = temp % 60;
    return result;

}


void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}

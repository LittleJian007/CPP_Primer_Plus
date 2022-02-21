#include "time0.h"

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

// Time Time::operator+(const Time &t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     sum.minutes %= 60;
//     return sum;
// }

// Time Time::operator-(const Time &t) const
// {
//     Time diff;
//     int a,b;
//     a = hours * 60 + minutes;
//     b = t.hours * 60 + t.minutes;
//     diff.hours = (a - b) / 60;
//     diff.minutes = (a - b) % 60;
//     return diff;
// }

// Time Time::operator*(double mlt) const
// {
//     Time result;
//     long temp = hours * 60 * mlt + minutes * mlt;
//     result.hours = temp / 60;
//     result.minutes = temp % 60;
//     return result;

// }

Time operator+(const Time &s,const Time &t)
{
    Time sum;
    sum.hours = s.hours + t.hours + (s.minutes + t.minutes) / 60;
    sum.minutes = (s.minutes + t.minutes) % 60;
    return sum;
}

Time operator-(const Time &s, const Time &t)
{
    Time diff;
    int tot1,tot2;
    tot1 = t.hours * 60 + t.minutes;
    tot2 = s.hours * 60 + s.minutes;

    diff.minutes = ((tot1 > tot2)? (tot1 -tot2):(tot2 - tot1)) % 60;
    diff.hours = ((tot1 > tot2)? (tot1 -tot2):(tot2 - tot1)) / 60;
    return diff;
}

Time  operator*(const Time &s, double mult)
{
    Time mult_t;
    long tot_minu = s.hours * mult * 60 + s.minutes * mult;
    mult_t.minutes = tot_minu % 60;
    mult_t.hours = tot_minu / 60;
    return mult_t;
}

Time  operator*(double mult, const Time &t)
{
    Time mult_t;
    long tot_minu = t.hours * mult * 60 + t.minutes * mult;
    mult_t.minutes = tot_minu % 60;
    mult_t.hours = tot_minu / 60;
    return mult_t;
}

ostream &operator<<(ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes." << endl;
    return os;
}

// void Time::Show() const
// {
//     std::cout << hours << " hours, " << minutes << " minutes";
// }

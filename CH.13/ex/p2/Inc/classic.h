#ifndef CLASSIC_H_
#define CLASSIC_H

#include <iostream>

using namespace std;

class Cd
{
private:
    char *preformers;
    char *lable;
    int selections;
    double playtime;

public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
    char *works;

public:
    Classic(const char *m, const char *s1, const char *s2, int n, double x);
    Classic(const char *m, const Cd &d);
    Classic(const Classic &c);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    Classic &operator=(const Classic &c);
};

#endif
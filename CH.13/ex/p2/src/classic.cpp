#include <cstring>
#include "classic.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    preformers = new char[strlen(s1) + 1];
    strcpy(preformers, s1);

    lable = new char[strlen(s2) + 1];
    strcpy(lable, s2);

    selections = n;
    playtime = x;
}

//复制函数
Cd::Cd(const Cd &d)
{
    preformers = new char[strlen(d.preformers) + 1];
    strcpy(preformers, d.preformers);

    lable = new char[strlen(d.lable) + 1];
    strcpy(lable, d.lable);

    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    preformers = NULL;
    lable = NULL;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete[] preformers;
    delete[] lable;
}

//对应输出
void Cd::Report() const
{
    cout << "Prrformers: " << preformers << endl;
    cout << "Lable: " << lable << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

//赋值或=运算符重载
Cd &Cd::operator=(const Cd &d)
{
    if (this == &d)
        return *this;
    
    delete []preformers;
    delete []lable;

    preformers = new char[strlen(d.preformers) + 1];
    strcpy(preformers, d.preformers);

    lable = new char[strlen(d.lable) + 1];
    strcpy(lable, d.lable);

    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char *m, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    strncpy(works, m, 50);
    if (strlen(m) >= 50)
        works[49] = '\0';
    else
        works[strlen(m)] = '\0';
}

Classic::Classic(const char *m, const Cd &d) : Cd(d)
{
    strncpy(works, m, 50);
    if (strlen(m) >= 50)
        works[49] = '\0';
    else
        works[strlen(m)] = '\0';
}

Classic::Classic() : Cd()
{
    works[0] = '\0';
}

Classic::Classic(const Classic &c) : Cd(c)
{
    strcpy(works, c.works);
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Works: " << works << endl;
}

Classic &Classic::operator=(const Classic &c)
{
    if (this == &c)
        return *this;
    Cd::operator=(c);
    strcpy(works, c.works);
    return *this;
}
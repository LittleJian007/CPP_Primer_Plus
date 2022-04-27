#include <cstring>
#include "classic.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    strncpy(preformers, s1, 49);
    if (strlen(s1) >= 50)
        preformers[49] = '\0';
    else
        preformers[strlen(s1)] = '\0';
    strncpy(preformers, s2, 19);
    if (strlen(s2) >= 20)
        lable[19] = '\0';
    else
        lable[strlen(s2)] = '\0';

    selections = n;
    playtime = x;
}

//复制函数
Cd::Cd(const Cd &d)
{
    strcpy(preformers, d.preformers);
    strcpy(lable, d.lable);

    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    preformers[0] = '\0';
    lable[0] = '\0';
    selections = 0;
    playtime = 0.0;
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
    strcpy(preformers, d.preformers);
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
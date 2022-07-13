#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
using namespace std;

class Worker
{
private:
    string fullname;
    long id;

public:
    Worker() : fullname("none one"), id(0) {}
    Worker(const string &s, long n) : fullname(s), id(n) {}

    virtual ~Worker() {}

    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker
{
private:
    int panache;

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(Worker &wk, int n = 0) : Worker(wk), panache(n) {}
    Waiter(const string &s, long i = 0, int p = 0) : Worker(s, i), panache(p) {}

    // ~Waiter() {} //析构函数与类继承

    virtual void Set();
    virtual void Show() const;
};

class Singer : public Worker
{
protected:
    enum
    {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    enum
    {
        Vtypes = 7
    };

private:
    static const char *pv[Vtypes]; // static用法：①面向过程；②面向对象（在声明中声明，在方法中初始化；）
    int vioce;

public:
    Singer() : Worker(), vioce(other) {}
    Singer(Worker &wk, int v) : Worker(wk), vioce(v) {}
    Singer(const string &s, long i, int v) : Worker(s, i), vioce(v) {}

    virtual void Set();
    virtual void Show() const;
};

#endif
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

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname("none one"), id(0) {}
    Worker(const string &s, long n) : fullname(s), id(n) {}

    virtual ~Worker() {}

    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const Worker &wk, int n = 0) : Worker(wk), panache(n) {}
    Waiter(const string &s, long i, int p = 0) : Worker(s, i), panache(p) {}

    void Set();
    void Show() const;
};

class Singer : public virtual Worker
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

    void Data() const;
    void Get();

private:
    static const char *pv[Vtypes];
    int vioce;

public:
    Singer() : Worker(), vioce(other) {}
    Singer(const Worker &wk, int v = other) : Worker(wk), vioce(v) {}
    Singer(const string &s, long i, int v = other) : Worker(s, i), vioce(v) {}

    virtual void Set();
    virtual void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const{}
    void Get(){}

public:
    SingingWaiter(){};
    SingingWaiter(const string &s, long i, int p = 0, int v = other) : Worker(s, i), Singer(s, i, p), Waiter(s, i, v) {}
    SingingWaiter(const Worker &wk, int p = 0, int v = other) : Worker(wk), Singer(wk, p), Waiter(wk, v) {}
    
    void Set();
    void Show() const;
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student : private string, private valarray<double> //使用私有继承方式
{
private:
    typedef valarray<double> ArrayDb;
    // std::string name;
    // ArrayDb ArrayDb;
    ostream &arr_out(ostream &os) const;
public:
    Student() : string("Null student"), ArrayDb() {} //私有继承时，继承类的初始化，将使用基类的类名来初始化
    Student(const string &s, int n) : string(s), ArrayDb(n) {}
    Student(const string &s, const ArrayDb &a) : string(s), ArrayDb(a) {}
    Student(const string &s, const double *pd, int n) : string(s), ArrayDb(pd, n) {}

    explicit Student(const int n) : string("Nully"), ArrayDb(n) {}
    explicit Student(const string &s) : string(s), ArrayDb() {}

    ~Student() {}

    void Set_name(const string &s);
    double Average() const;
    const string &Name() const;
    double &operator[](int n);      // stu[0] = 1,作为左值使用
    double operator[](int n) const; // a = stu[0],作为右值使用

    friend istream &operator>>(istream &is, Student &stu);
    friend istream &getline(istream &is, Student &stu);
    friend ostream &operator<<(ostream &os, const Student &stu);
};

#endif
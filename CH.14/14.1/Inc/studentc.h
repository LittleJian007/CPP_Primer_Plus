#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student
{
private:
    std::string name;
    typedef valarray<double> ArrayDb;
    ArrayDb scores;

public:
    Student() : name("Null student"), scores() {}
    Student(const string &s, int n) : name(s), scores(n) {}
    Student(const string &s, const ArrayDb &a) : name(s), scores(a) {}
    Student(const string &s, const double *pd, int n) : name(s), scores(pd, n) {}

    explicit Student(const int n) : name("Nully"), scores(n) {}
    explicit Student(const string &s) : name(s), scores() {}

    ~Student() {}

    double Average() const;
    const string &Name() const;
    double &operator[](int n);      // stu[0] = 1,作为左值使用
    double operator[](int n) const; // a = stu[0],作为右值使用

    friend istream &operator>>(istream &is, Student &stu);
    friend istream &getline(istream &is,Student &stu);
    friend ostream &operator<<(ostream &os,const Student &stu);

};

#endif
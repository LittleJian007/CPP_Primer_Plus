#include "studentc.h"

double Student::Average() const
{
    if (ArrayDb::size() > 0) //继承类中访问基类的方法：通过“类名”+“::”作用域解析运算符来范围基类中方法
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}

const string &Student::Name() const
{
    return (const string &)*this; //继承类中访问基类的对象：使用强制类型转换
}

double &Student::operator[](int n)
{
    return ArrayDb::operator[](n);
}

double Student::operator[](int n) const
{
    return ArrayDb::operator[](n);
}

istream &operator>>(istream &is, Student &stu)
{
    //访问基类的友元函数：将继承类，用显式转换为基类，从而调用基类的友元函数
    //如：将stu显式的转换为string对象引用，进而调用operator>>(ostream &, string &)
    is >> (string &)stu;
    return is;
}

istream &getline(istream &is, Student &stu)
{
    getline(is, (string &)stu);
    return is;
}

ostream &Student::arr_out(ostream &os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << "Empty array!" << endl;
    return os;
}

ostream &operator<<(ostream &os, const Student &stu)
{
    os << "Scores for " << (string &)stu << ":" << endl;
    stu.arr_out(os);
    return os;
}

void Student::Set_name(const string &s)
{
    (string &)*this= s;
}
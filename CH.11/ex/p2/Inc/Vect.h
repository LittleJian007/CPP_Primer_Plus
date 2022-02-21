#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        //定义两种坐标：RECT-直角坐标系，POL-极坐标系
        enum Mode
        {
            RECT,
            POL
        };

    private:
        //定义直角坐标系、极坐标系下的参数
        double x;
        double y;
        // double mag;
        // double ang;

        //定义坐标系类型参数
        Mode mode;

        //赋值
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);
        // void set_mag();
        // void set_ang();

    public:
        Vector();
        Vector(double n1, double n2, Mode from = RECT);
        void reset(double n1, double n2, Mode from = RECT);

        ~Vector();

        // 获取值
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const;
        double angval() const;

        //设置坐标系
        void polar_mode();
        void rect_mode();

        //运算符号重载
        Vector operator+(const Vector &b) const; //两数相加
        Vector operator-(const Vector &b) const; //两数相减
        Vector operator-() const;                //取负值操作
        Vector operator*(double n) const;        //倍数操作

        //友元函数
        friend Vector operator*(double n, const Vector &a); //
        friend std::ostream &operator<<(std::ostream &os, const Vector &t);
    };
}

#endif
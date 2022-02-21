#include "Vect.h"
#include <cmath>

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    void Vector::set_x()
    {
        x = mag * sin(ang);
    }

    void Vector::set_y()
    {
        y = mag * cos(ang);
    }

    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0 && y == 0)
            ang = 0;
        else
            ang = atan2(y, x);
    }

    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::~Vector()
    {
    }

    Vector::Vector(double n1, double n2, Mode from)
    {
        mode = from;
        if (from == RECT)
        {
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        }
        else if (from == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "错误输入，重置坐标系！";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode from)
    {
        mode = from;
        if (from == RECT)
        {
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        }
        else if (from == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            std::cout << "错误输入，重置坐标系！";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &t)
    {
        if (t.mode == Vector::RECT)
        {
            os << "x, y = " << t.x << ", " << t.y << ". ";
        }
        else if (t.mode == Vector::POL)
        {
            os << "mag, ang = " << t.mag << ", " << t.ang << ". ";
        }
        else
            os << "坐标系错误！";
        return os;
    }

}

#include "Vect.h"
#include <cmath>

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    void Vector::set_x(double mag, double ang)
    {
        x = mag * sin(ang);
    }

    void Vector::set_y(double mag, double ang)
    {
        y = mag * cos(ang);
    }

    // void Vector::set_mag()
    // {
    //     mag = sqrt(x * x + y * y);
    // }

    // void Vector::set_ang()
    // {
    //     if (x == 0 && y == 0)
    //         ang = 0;
    //     else
    //         ang = atan2(y, x);
    // }

    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
    }

    Vector::Vector()
    {
        x = y = 0.0;
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
        }
        else if (from == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        }
        else
        {
            std::cout << "错误输入，重置坐标系！";
            x = y = 0.0;
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
        }
        else if (from == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        }
        else
        {
            std::cout << "错误输入，重置坐标系！";
            x = y = 0.0;
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
            os << "mag, ang = " << t.magval() << ", " << t.angval() << ". ";
        }
        else
            os << "坐标系错误！";
        return os;
    }

}

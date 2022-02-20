#include "vect.h"
#include <ctime>
#include <cstdlib>
using namespace VECTOR;
using namespace std;

int main()
{
    double direction;
    Vector result(0.0, 0.0, Vector::POL);
    Vector step;
    double target;
    double dstep;
    unsigned steps = 0;
    srand(time(NULL));
    cout << "请输入距离(q：退出)： " << endl;
    while (cin >> target)
    {
        cout << "请输入步长：" << endl;
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << steps << " 步后，超出 " << target << " 范围。" << endl;
        cout << "Now: " << result << endl;
        result.polar_mode();
        cout << "Now: " << result << endl;

        steps = 0;
        result.reset(0.0, 0.0);

        cout << "请输入距离(q：退出)： " << endl;
    }
    cout << "拜拜！";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}
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
    int N = 0;
    unsigned int max = 0;
    unsigned int min = 0;
    unsigned int sum = 0;

    cout << "请输入距离(q：退出)： ";
    cin >> target;
    cout << "请输入步长：";
    cin >> dstep;
    cout << "请输入测试次数： ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
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

        max = (max > steps) ? max : steps;
        if (min == 0)
            min = max;
        min = (min < steps) ? min : steps;
        sum += steps;

        steps = 0;
        result.reset(0.0, 0.0);
    }

    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
    cout << "average:" << (double)sum / N << endl;

    cout << "拜拜！";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}
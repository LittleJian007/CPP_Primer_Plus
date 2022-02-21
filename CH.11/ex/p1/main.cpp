#include "vect.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
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

    ofstream fout;
    fout.open("randwalk.txt");

    cout << "请输入距离(q：退出)： " << endl;
    while (cin >> target)
    {
        cout << "请输入步长：" << endl; 
        if (!(cin >> dstep))
            break;
            result.rect_mode();
        fout << "距离： " << target << ", " << " 步长： " << dstep << ". \n";
        while (result.magval() < target)
        {
            fout << steps << ": " << result << endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << steps << " 步后，超出 " << target << " 范围。" << endl;
        fout << steps << " 步后，超出 " << target << " 范围。" << endl;

        cout << "Now: " << result << endl;
        fout << "Now: " << result << endl;

        result.polar_mode();
        cout << "Now: " << result << endl;
        fout << "Now: " << result << endl;
        fout << "per step: " << result.magval()/steps << endl;

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
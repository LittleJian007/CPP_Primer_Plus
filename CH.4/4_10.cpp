#include <iostream>
using namespace std;
int main()
{
    double wages[] = {10000.0, 20000.0, 30000.0,};
    short stacks[] = {3, 2, 1};

    double *pw = wages;
    short *pt = &stacks[0];

    cout << "pw = " << pw <<", *pw = " << *pw << endl;

    cout << "stacks[0] = " << *(pt + 1) << endl;          //指针方式访问数组中内容
    cout << "stacks[0] = " << pt[2] << endl;              //数组方式访问指针数组中内容

    int *pa = new int [3];                              //new运算符创建指针数组
    pa[0] = 1;                                          //数组赋值方式为每个赋值
    pa[1] = 2;
    pa[2] = 3;

    cout << *pa << ", " << *(pa+1) << endl;             //通过指针访问指针数组中的内容
    delete [] pa;
    // system ("pause");
    return 0;
}
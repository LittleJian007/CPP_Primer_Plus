/*使用指针*/

#include <iostream>
#include "Brass.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

const int CLIENTS = 3;
int main()
{
    Brass *p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "请输入账户名称：";
        getline(cin, temp);
        cout << "请输入账户编号：";
        cin >> tempnum;
        cout << "开户存款金额：";
        cin >> tempbal;
        cout << "请输入账户类型（1:普通存款账户，2:透支账户）：";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "输入的参数错误，请输入1或2";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "请输入账户透支额度：";
            cin >> tmax;
            cout << "请输入利率：";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for(int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "完成!!!\n";
    return 0;
}
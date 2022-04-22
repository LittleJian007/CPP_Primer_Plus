/*使用类的对象*/

#include "Brass.h"

using std::cout;
using std::endl;
int main0()
{
    Brass xiaoming("zhang xiaoming", 622456, 5000.00);
    xiaoming.ViewAcct();
    xiaoming.Deposit(1000.00);
    xiaoming.ViewAcct();
    xiaoming.Withdraw(50000.00); //取款超出账号余额
    xiaoming.Withdraw(2000.00);
    xiaoming.Balance();
    xiaoming.ViewAcct();
    std::cout << "-----------------" << std::endl;
    BrassPlus xiao(xiaoming, 622345, 10000.0);
    BrassPlus xiaohong("xiaohong", 622345, 10000.0);
    xiaohong.ViewAcct();
    xiaohong.Withdraw(1000.0);
    xiaohong.ViewAcct();

    return 0;
}
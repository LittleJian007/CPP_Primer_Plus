#include "acctabc.h"

using std::cout;
using std::endl;

//创建账户
AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

//存款
void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "存款金额不能为负值！！！" << endl;
    else
        balance += amt;
}

//取款
void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

//取款
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "取款金额不能为负值！！！" << endl;
    else if (amt > Balance())
    {
        cout << "取款金额不能大于存款额度！！！" << endl;
        cout << "您的取款金额最大为：" << Balance() << endl;
    }
    else
        AcctABC::Withdraw(amt);
}

//显示账户信息
void Brass::ViewAcct() const
{
    cout << "客户姓名：" << FULLNAME() << endl;
    cout << "账户ID： " << AcctNum() << endl;
    cout << "存款金额：$" << Balance() << endl;
}

//创建带有透支功能的账户，默认构造函数创建
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

//创建账户-通过基类创建
BrassPlus::BrassPlus(const AcctABC &ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

//显示账户信息
void BrassPlus::ViewAcct() const
{
    cout << "客户姓名：" << FULLNAME() << endl;
    cout << "账户ID： " << AcctNum() << endl;
    cout << "存款金额：$" << Balance() << endl;
    cout << "最大透支额度：$" << maxLoan << endl;
    cout << "当前利率：" << rate << endl;
    cout << "当前透支额度：$" << owesBank << endl;
    cout << "当前透支余额：$" << maxLoan - owesBank << endl;
}

//取款
void BrassPlus::Withdraw(double amt)
{
    double bal = Balance();
    if (bal > amt)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank = advance * (1.0 + rate);
        cout << "当前已透支额度: $" << advance << endl;
        cout << "费率金额：$" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
    {
        cout << "超出取款最大额度！！！" << endl;
        cout << "最大取款额度为：$" << bal + maxLoan - owesBank << endl;
    }
}

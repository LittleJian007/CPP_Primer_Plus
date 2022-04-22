#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

class AcctABC
{
private:
    std::string fullName; //客户姓名
    long acctNum;         //账户编号
    double balance;       //账户当前存款金额

protected:
    const std::string &FULLNAME() const { return fullName; }
    long AcctNum() const { return acctNum; }

public:
    AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0); //构造函数，创建账户
    void Deposit(double amt);                                                   //存款
    virtual void Withdraw(double amt) = 0;                                      //取款，纯虚函数
    double Balance() const { return balance; }                                  //获取账户当前金额
    virtual void ViewAcct() const = 0;
    virtual ~AcctABC() {}
};

class Brass : public AcctABC
{
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0)
        : AcctABC(s, an, bal) {}       //创建账户，默认构造函数+内联函数
    virtual void Withdraw(double amt); //取款
    virtual void ViewAcct() const;     //显示账户信息
    virtual ~Brass(){};                //析构函数
};

class BrassPlus : public AcctABC
{
private:
    double maxLoan;  //贷款额度
    double rate;     //贷款利率
    double owesBank; //当前透支额度
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500.00, double r = 0.1);                  //透支默认构造函数
    BrassPlus(const AcctABC &ba, double ml = 500.00, double r = 0.1); //通过Brass对象创建
    virtual void ViewAcct() const;                                  //显示账户信息
    virtual void Withdraw(double amt);                              //取款
    void ResetMax(double m) { maxLoan = m; }                        //设置贷款额度
    void ResetRate(double r) { rate = r; }                          //设置贷款利率
    void ResetOwes() { owesBank = 0.0; }                            //当前透支额度归零
};

#endif
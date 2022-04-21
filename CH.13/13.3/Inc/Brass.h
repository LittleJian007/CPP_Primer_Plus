#ifndef BRASS_H_
#define BRASS_H_

#include <iostream>
#include <string>

class Brass
{
private:
    std::string fullName; //客户姓名
    long acctNum;         //账户
    double balance;       //当前存款
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0); //创建账户，默认构造函数
    void Deposit(double amt);                                                 //存款
    virtual void Withdraw(double amt);                                        //取款
    double Balance() const;                                                   //查询账户存款
    virtual void ViewAcct() const;                                            //显示账户信息
    virtual ~Brass(){};                                                       //析构函数
};

class BrassPlus : public Brass
{
private:
    double maxLoan;  //贷款额度
    double rate;     //贷款利率
    double owesBank; //当前透支额度
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500.00, double r = 0.11125);                     //透支默认构造函数
    BrassPlus(const Brass &ba, double ml = 500.00, double rate = 0.11125); //通过Brass对象创建
    virtual void ViewAcct() const;                                         //显示账户信息
    virtual void Withdraw(double amt);                                     //取款
    void ResetMax(double m) { maxLoan = m; }                               //设置贷款额度
    void ResetRate(double r) { rate = r; }                                 //设置贷款利率
    void ResetOwes() { owesBank = 0.0; }                                   //当前透支额度归零
};

#endif
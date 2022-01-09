#ifndef __STOCK00_H__
#define __STOCK00_H__

#include <string>


class Stock
{
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot()
            {
            total_val = shares * share_val;
            }
    public:
        // 构造函数 写法
        // Stock(const std::string &co, long n, double pr);

        // 默认构造函数 写法1
        Stock(const std::string &co ="HuaWei" , long n = 0 , double pr = 0.0);
        

        void buy(long num , double price);
        void sell(long num , double price);
        void update(double price);
        void show();
};

#endif
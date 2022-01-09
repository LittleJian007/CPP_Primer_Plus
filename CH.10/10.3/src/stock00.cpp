#include <iostream>
#include "stock00.h"

Stock::Stock(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
     {
        std::cout << "您输入的值不可为负数；"<< company << "股票设置为0。\n";
        shares = 0;
    }
    else
        shares = n;
        share_val = pr;
        set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    std::cout << "您购买的股票不可为负数，尝试失败!\n";
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    std::cout << "您卖出的股票数不可为负数!\n";
    else if (num > shares )
    {
        std::cout << "您卖出的股票数超过您持有的股票数!\n";
    }
    else
    {
        shares -=num;
        share_val = price;
        set_tot();
    }
}


void Stock::show()
{
    std::cout << "股票公司：" << company << std::endl;
    std::cout << "股票股数：" << shares << std::endl;
    std::cout << "股票价格：$" << share_val << std::endl;
    std::cout << "股票总价：$" << total_val << std::endl;
    std::cout << "-----------------\n";

}
#include <iostream>
#include "stonewt.h"

int main()
{
    Stonewt incognito = 275;    //类的自动转换；Stonewt incognito （275）或Stonewt incognito = Stonewt(276.8)
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    incognito.show_stn();
    wolfe.show_stn();
    taft.show_lbs();

    std::cout <<"--------------\n";

    incognito = 276.8;  
    taft = 325; 

    incognito.show_stn();
    taft.show_lbs();

    std::cout << "--------\n";
    int a = incognito.stone_to_int();   //类的方法显式转换
    int b = int(wolfe);                 //强制转换
    double c = taft;                    //隐式转换
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}
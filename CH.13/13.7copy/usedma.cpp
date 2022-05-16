#include "dma.h"

int main()
{
    baseDMA base1("Base_1", 1);

    cout << "Playing baseDMA object:" << endl;
    cout << base1;
    cout << "-------------------------\n";

    baseDMA base2 = base1; //复制函数
    cout << base2;
    cout << "-------------------------\n";

    baseDMA base3;
    base3 = base1; //赋值函数
    cout << base3;
    cout << "-------------------------\n";

    cout << "Playing lacksDMA object:" << endl;
    lacksDMA laks1("Lacks1", 10, "red");
    cout << laks1;
    cout << "-------------------------\n";

    lacksDMA laks2 = laks1;
    cout << laks2;
    cout << "-------------------------\n";

    lacksDMA laks3;
    laks3 = laks2;
    cout << laks3;
    cout << "-------------------------\n";

    lacksDMA laks4(base1,"yello");
    cout << laks4;
    cout << "-------------------------\n";

    cout << "Playing hasDMA object:" << endl;
    hasDMA has1(base2, "keys");
    cout << has1;

    return 0;
}
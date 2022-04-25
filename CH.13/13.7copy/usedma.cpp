#include "dma.h"

int main()
{
    baseDMA base1("Base_1", 1);

    cout << "Playing baseDMA object:" << endl;
    cout << base1;

    baseDMA base2;
    base2 = base1;
    cout << base2;

    return 0;
}
#include <iostream>
#include "dma.h"

using std::cout;
using std::endl;

int main()
{
    baseDMA shirt("Protabelly", 8);
    lacksDMA balloon("Blimpo", 4, "red");

    cout << "Displaying baseMDA object: \n";
    cout << shirt << endl;

    cout << "Displaying lacksDMA object: \n";
    cout << balloon << endl;

    hasDMA map("Mercator", 5, "keys");
    hasDMA map2 = map;
    // map2 = map;
    cout << "Displaying hasDMA object:\n";
    cout << map2 << endl;

    return 0;
}
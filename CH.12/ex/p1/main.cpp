#include "Cow.h"

int main()
{
    Cow cow1;
    cow1.ShowCow();
    Cow cow2("LaoLiiiiiiiiiiiiiijk", "badminton", 123);
    Cow cow3(cow2);

    cow1 = cow2;

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    return 0;
}
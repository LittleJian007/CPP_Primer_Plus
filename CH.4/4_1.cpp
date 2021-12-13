#include <iostream>
int main ()
{
    int array[3] = {1,2,1};
    for (int i = 0; i < 3; i++)
        std::cout << array[i] << std::endl;
    std::cout << sizeof(array) << std::endl;
    std::cout << sizeof(array[0]) << std::endl;

    return 0;
}
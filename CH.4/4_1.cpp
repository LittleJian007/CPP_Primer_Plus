#include <iostream>
int main ()
{
    int array[3] = {1,2,1};
    for (int i = 0; i < 3; i++)
        std::cout << array[i] << std::endl;
    std::cout << sizeof(array) << std::endl;        //数组名sizeof，表示该数组专用字节数
    std::cout << sizeof(array[0]) << std::endl;     //数组元素sizeof，表示该元素占用字节数

    return 0;
}
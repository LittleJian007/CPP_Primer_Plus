#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char array[4] = "dog";
    for (int i = 0; i < strlen(array); i++)
        std::cout << array[i] << std::endl;
    std::cout << sizeof(array) << std::endl;
    std::cout << sizeof(array[0]) << std::endl;

    char name[] = "zhangjian";
    char name1[10];
    std::cout << name << std::endl;

    cin.getline(name, 10);

    cout << "name:" << name << endl;
    cin.clear();
    cin.getline(name1, 10);
    cout << "name:" << name1 << endl;
    system("pause");
    return 0;
}

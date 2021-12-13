#include <iostream>
#include <string>

int main ( )
{
    using namespace std;
    //使用string类储存字符串
    string word;
    cin >>word;
    for (int i = word.size()-1;i>=0;i--)
    cout<<word[i];
    cout<<"\nBye.\n";
    //使用char数组储存字符串
    char word_1[20];
    cin.getline(word_1,20);
    for (int i=(sizeof(word_1)/sizeof(word_1[0]));i>=0;i--)
    cout<<word_1[i];
    cout<<"\nBye.\n";
    return 0;
}
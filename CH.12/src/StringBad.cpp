#include "StringBad.h"
#include <cstring>

int StringBad::num_string = 0;

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_string++;
    std::cout << num_string << ": \"" << str << "\" 被创建。\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_string++;
    std::cout << num_string << ": \"" << str << "\" 被创建。\n";
}

StringBad::~StringBad()
{
    std::cout << "\"" << str << "\" 被删除。\n";
    num_string--;
    std::cout << num_string << " 个剩余。\n";
    delete[] str;
}

std::ostream &operator<<(std::ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}
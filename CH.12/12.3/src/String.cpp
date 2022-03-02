
#include <cstring>
#include "Strng.h"

int String::num_strings = 0;

int String::HowMany() //第几个字符串
{
    return num_strings;
}

String::String(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
    // cout << num_strings << ": \"" << str << ".\"" << endl;
}

String::String()
{
    len = 0;
    str[0] = '\0';
    num_strings++;
    // cout << num_strings << ": \"" << str << ".\"" << endl;
}

String::String(const String &st)
{
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    num_strings++;
    // cout << num_strings << ": \"" << str << ".\"" <<endl;
}

String::~String()
{
    // cout << "\"" << str << "\"" << " object deleted." << endl;
    --num_strings;
    // cout << num_strings << " left." <<endl;
    delete[] str;
}

String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char(len + 1);
    strcpy(str, st.str);
    return *this;
}

String &String::operator=(const char *s)
{
    // delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char &String::operator[](int i)
{
    return str[i];
}

const char &String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) < 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str2 < str1;
}

bool operator==(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st)
{
    // cin  cin.get
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
}

#include "StringBad.h"
#include <cstring>

int StringBad::num_strings = 0;

StringBad::StringBad(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\"" << " object deleted." << endl;
    --num_strings;
    cout << num_strings << " left." <<endl;
    delete []str;
}

ostream &operator<<(ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}
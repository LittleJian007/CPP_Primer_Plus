// 1.
// 2.  
    #include <iostream>
    #include <cstring>
    class String
    {
        int len;
        char * str;
         pubilc:
            String(const char *s);


    };
    String::String(const char *s)
    {
        len = strlen(s);
        str = new char[len +1];
        strcpy(str, s);
        
    }
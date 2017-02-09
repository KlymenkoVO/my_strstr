#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
char * my_strstr(char * str1, const char * str2)
{
    assert(str1);
    assert(str2);
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    assert(len2<len1);

    for (size_t i = 0; i < len1; i++)
    {
        if (str1[i] == str2[0])
        {
            bool flag = true;
            for (size_t j = 1; j < len2; j++)
            {
                if (str1[i + j] != str2[j])
                    flag = false;
            }
            if (flag)
                return (str1 + i);
        }
    }
    return NULL;
}


int main()
{
    char *str1 = "Hi my name is Fedir";
    char *str2 = "dir";

    cout<<"my_strstr: "<<my_strstr(str1, str2)<<endl;
    cout<<"cstring  : "<<strstr(str1,str2)<<endl;
    return 0;
}

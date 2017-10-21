#include "gtest/gtest.h"
#include "my_strstr.h"

TEST(my_strstr, my_strstr)
{
    const char *str = "Hi, my name is Denys!";
    
    ASSERT_EQ(str + 0, my_strstr(str, "Hi"));
    ASSERT_EQ(str + 2, my_strstr(str, ","));
    ASSERT_EQ(str + 3, my_strstr(str, " "));
    ASSERT_EQ(str + 4, my_strstr(str, "my"));
    ASSERT_EQ(str + 7, my_strstr(str, "name"));
    ASSERT_EQ(str + 12, my_strstr(str, "is"));
    ASSERT_EQ(str + 15, my_strstr(str, "Denys"));
    // ASSERT_EQ(str + 20, my_strstr(str, "!"));
    // ASSERT_EQ(str + 0, my_strstr(str, ""));
    ASSERT_EQ(NULL, my_strstr(str, "ABABAGALAMAGA"));
}

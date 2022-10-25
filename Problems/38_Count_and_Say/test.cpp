#include <gtest/gtest.h>
#include "main.h"

TEST (Testing, BaseCase)
{
    EXPECT_EQ(Solution().countAndSay(1), "1");
}

TEST (Testing, DefaultTest)
{
    EXPECT_EQ(Solution().countAndSay(4), "1211");
}

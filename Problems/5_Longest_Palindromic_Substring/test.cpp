#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    EXPECT_EQ(Solution().longestPalindrome("babad"), "bab");
}

TEST(Testing, SecondDefaultTest)
{
    EXPECT_EQ(Solution().longestPalindrome("cbbd"), "bb");
}

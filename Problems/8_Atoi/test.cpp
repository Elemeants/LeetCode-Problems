#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    EXPECT_EQ(Solution().myAtoi("123"), 123);
}

TEST(Testing, NegativeCase)
{
    EXPECT_EQ(Solution().myAtoi("-123"), -123);
}

TEST(Testing, WithLeadingSpaces)
{
    EXPECT_EQ(Solution().myAtoi("   12"), 12);
}

TEST(Testing, WithLeadingSpacesNegative)
{
    EXPECT_EQ(Solution().myAtoi("   -12"), -12);
}

TEST(Testing, WithWords)
{
    EXPECT_EQ(Solution().myAtoi("4193 with words"), 4193);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    EXPECT_EQ(Solution().reverse(123), 321);
}

TEST(Testing, NegativeCase)
{
    EXPECT_EQ(Solution().reverse(-123), -321);
}

TEST(Testing, WithLeadingZeros)
{
    EXPECT_EQ(Solution().reverse(120), 21);
}

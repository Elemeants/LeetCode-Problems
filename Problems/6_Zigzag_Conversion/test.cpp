#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    EXPECT_EQ(Solution().convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(Testing, SecondDefaultTest)
{
    EXPECT_EQ(Solution().convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(Testing, TestWithStringOfSize1)
{
    EXPECT_EQ(Solution().convert("A", 1), "A");
}

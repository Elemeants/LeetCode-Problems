#include <gtest/gtest.h>
#include "main.h"

TEST (Testing, DefaultTest)
{
    EXPECT_EQ(Solution().minPartitions("32"), 3);
}

TEST (Testing, SecondDefaultTest)
{
    EXPECT_EQ(Solution().minPartitions("82734"), 8);
}

TEST (Testing, TestLongNumber)
{
    EXPECT_EQ(Solution().minPartitions("27346209830709182346"), 9);
}

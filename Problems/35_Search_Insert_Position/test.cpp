#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::vector<int> i = {1,3,5,6};
    EXPECT_EQ (Solution().searchInsert(i, 5), 2);
}

TEST(Testing, TestGetIndexNumberInnerArray)
{
    std::vector<int> i = {1,3,5,6};
    EXPECT_EQ (Solution().searchInsert(i, 2), 1);
}

TEST(Testing, TestGetIndexNumberHigherBound)
{
    std::vector<int> i = {1,3,5,6};
    EXPECT_EQ (Solution().searchInsert(i, 7), 4);
}

TEST(Testing, TestGetIndexNumberLowerBound)
{
    std::vector<int> i = {1,3,5,6};
    EXPECT_EQ (Solution().searchInsert(i, -1), 0);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::vector<int> input    = {0,1,0,3,12};
    std::vector<int> expected = {1,3,12,0,0};
    Solution().moveZeroes(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, AllZeros)
{
    std::vector<int> input    = {0,0,0,0,0};
    std::vector<int> expected = {0,0,0,0,0};
    Solution().moveZeroes(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, CheckingOrder)
{
    std::vector<int> input    = {0,1,2,3,4};
    std::vector<int> expected = {1,2,3,4,0};
    Solution().moveZeroes(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, NoZeros)
{
    std::vector<int> input    = {1,2,3,4,5};
    std::vector<int> expected = {1,2,3,4,5};
    Solution().moveZeroes(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, OnlyOneElement)
{
    std::vector<int> input    = {0};
    std::vector<int> expected = {0};
    Solution().moveZeroes(input);
    EXPECT_EQ(input, expected);
}

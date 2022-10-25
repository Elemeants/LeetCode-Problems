#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::vector<int> input = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(Solution().search(input, 9), 4);
}

TEST(Testing, ReturnMinusOneWhenTheNumberIsNotFound)
{
    std::vector<int> input = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(Solution().search(input, 2), -1);
}

TEST(Testing, ReturnMinusOneWhenTheNumberIsNotFoundAndNumberIsOutsideHigherBound)
{
    std::vector<int> input = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(Solution().search(input, 15), -1);
}

TEST(Testing, ReturnMinusOneWhenTheNumberIsNotFoundAndNumberIsOutsideLowerBound)
{
    std::vector<int> input = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(Solution().search(input, -20), -1);
}

TEST(Testing, TestCaseOnLowerNumbers)
{
    std::vector<int> input = {-1,0,5};
    EXPECT_EQ(Solution().search(input, 2), -1);
}
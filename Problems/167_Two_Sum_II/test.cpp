#include <gtest/gtest.h>
#include "main.h"

TEST(DoublePointerTesting, DefaultTest)
{
    std::vector<int> input    = {2,7,11,15};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(Solution().twoSum(input, 9), expected);
}

TEST(DoublePointerTesting, BaseCaseArraySize2)
{
    std::vector<int> input    = {-1, 0};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(Solution().twoSum(input, -1), expected);
}

TEST(DoublePointerTesting, SearchForZeros)
{
    std::vector<int> input    = {0,0,3,4};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(Solution().twoSum(input, 0), expected);
}

TEST(DoublePointerTesting, LongTestCase)
{
    std::vector<int> input(40000);
    std::iota(input.begin(), input.end(), -20000);
    std::vector<int> expected = {20003, 40000};
    EXPECT_EQ(Solution().twoSum(input, 20001), expected);
}

TEST(MapTesting, DefaultTest)
{
    std::vector<int> input    = {2,7,11,15};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(MapSolution().twoSum(input, 9), expected);
}

TEST(MapTesting, BaseCaseArraySize2)
{
    std::vector<int> input    = {-1, 0};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(MapSolution().twoSum(input, -1), expected);
}

TEST(MapTesting, LongTestCase)
{
    std::vector<int> input(40000);
    std::iota(input.begin(), input.end(), -20000);
    std::vector<int> expected = {20003, 40000};
    EXPECT_EQ(MapSolution().twoSum(input, 20001), expected);
}

TEST(MapTesting, SearchForZeros)
{
    std::vector<int> input    = {0,0,3,4};
    std::vector<int> expected = {1,2};
    EXPECT_EQ(Solution().twoSum(input, 0), expected);
}

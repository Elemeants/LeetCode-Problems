#include <gtest/gtest.h>
#include <algorithm>
#include "main.h"

TEST(Test77, DefaultTest)
{
    listOfCombinations result = Solution().combine(4, 2);
    listOfCombinations expected = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, LargeNSingleKShouldBeAnArrayOfLenghtN)
{
    listOfCombinations result = Solution().combine(5, 1);
    listOfCombinations expected = {{1}, {2}, {3}, {4}, {5}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, LargeKButSingleCombination)
{
    listOfCombinations result = Solution().combine(5, 5);
    listOfCombinations expected = {{1, 2, 3, 4, 5}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, SingleCombination)
{
    listOfCombinations result = Solution().combine(1, 1);
    listOfCombinations expected = {{1}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, KEqualTo3)
{
    listOfCombinations result = Solution().combine(4, 3);
    listOfCombinations expected =
        {
            {1, 2, 3},
            {1, 2, 4},
            {1, 3, 4},
            {2, 3, 4}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, KEqualTo4)
{
    listOfCombinations result = Solution().combine(5, 4);
    listOfCombinations expected =
        {
            {1, 2, 3, 4},
            {1, 2, 3, 5},
            {1, 2, 4, 5},
            {1, 3, 4, 5},
            {2, 3, 4, 5}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

TEST(Test77, Nto5_Kto3)
{
    listOfCombinations result = Solution().combine(5, 3);
    listOfCombinations expected =
        {
            {1, 2, 3},
            {1, 2, 4},
            {1, 2, 5},
            {1, 3, 4},
            {1, 3, 5},
            {1, 4, 5},
            {2, 3, 4},
            {2, 3, 5},
            {2, 4, 5},
            {3, 4, 5}};

    EXPECT_EQ(expected.size(), result.size());
    EXPECT_EQ(expected[0].size(), result[0].size());
    EXPECT_EQ(expected, result);
}

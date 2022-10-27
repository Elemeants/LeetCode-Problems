#include <gtest/gtest.h>
#include "main.h"

TEST(Test_MapSolution, DefaultTest)
{
    const std::vector<int> expected = {0,1,9,16,100};
    EXPECT_EQ(MapSolution().sortedSquares(std::vector<int>{-4,-1,0,3,10}), expected);
}

TEST(Test_MapSolution, SecondDefaultTest)
{
    const std::vector<int> expected = {4,9,9,49,121};
    EXPECT_EQ(MapSolution().sortedSquares(std::vector<int>{-7,-3,2,3,11}), expected);
}

TEST(Test_MapSolution, LongVersion)
{
    std::vector<int> input(40000);
    std::iota(input.begin(), input.end(), 0);
    std::vector<int> expected(40000);
    std::transform(input.begin(), input.end(), expected.begin(), [](const int& v) -> int { return v * v; });

    EXPECT_EQ(MapSolution().sortedSquares(input), expected);
}

TEST(Test_IteratorSolution, DefaultTest)
{
    const std::vector<int> expected = {0,1,9,16,100};
    EXPECT_EQ(IteratorSolution().sortedSquares(std::vector<int>{-4,-1,0,3,10}), expected);
}

TEST(Test_IteratorSolution, SecondDefaultTest)
{
    const std::vector<int> expected = {4,9,9,49,121};
    EXPECT_EQ(IteratorSolution().sortedSquares(std::vector<int>{-7,-3,2,3,11}), expected);
}

TEST(Test_IteratorSolution, LongVersion)
{
    std::vector<int> input(40000);
    std::iota(input.begin(), input.end(), 0);
    std::vector<int> expected(40000);
    std::transform(input.begin(), input.end(), expected.begin(), [](const int& v) -> int { return v * v; });

    EXPECT_EQ(IteratorSolution().sortedSquares(input), expected);
}
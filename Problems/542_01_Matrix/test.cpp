#include <gtest/gtest.h>
#include "main.h"

TEST(Test542, DefaultTest)
{
    matrix2D input = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}};
    matrix2D output = {{0, 0, 0},
                       {0, 1, 0},
                       {1, 2, 1}};
    EXPECT_EQ(Solution().updateMatrix(input), output);
}

TEST(Test542, NoUpdatedMatrix)
{
    matrix2D input = {{0, 0, 0},
                      {0, 1, 0},
                      {0, 0, 0}};
    matrix2D output = {{0, 0, 0},
                       {0, 1, 0},
                       {0, 0, 0}};
    EXPECT_EQ(Solution().updateMatrix(input), output);
}

TEST(Test542, LargeMatrix)
{
    matrix2D input = {{1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {1, 1, 1},
                      {0, 0, 0}};
    matrix2D output = {{19, 19, 19},
                       {18, 18, 18},
                       {17, 17, 17},
                       {16, 16, 16},
                       {15, 15, 15},
                       {14, 14, 14},
                       {13, 13, 13},
                       {12, 12, 12},
                       {11, 11, 11},
                       {10, 10, 10},
                       {9, 9, 9},
                       {8, 8, 8},
                       {7, 7, 7},
                       {6, 6, 6},
                       {5, 5, 5},
                       {4, 4, 4},
                       {3, 3, 3},
                       {2, 2, 2},
                       {1, 1, 1},
                       {0, 0, 0}};
    EXPECT_EQ(Solution().updateMatrix(input), output);
}
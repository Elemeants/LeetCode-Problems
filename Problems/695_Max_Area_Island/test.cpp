#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    vector2D input = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int expected = 6;
    EXPECT_EQ(
        Solution().maxAreaOfIsland(input),
        expected);
}

TEST(Testing, AllZeros)
{
    vector2D input = {{0,0,0,0,0,0,0,0}};
    int expected = 0;
    EXPECT_EQ(
        Solution().maxAreaOfIsland(input),
        expected);
}

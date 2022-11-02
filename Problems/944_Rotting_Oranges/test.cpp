#include <gtest/gtest.h>
#include "main.h"

// 0 empty
// 1 fresh orange
// 2 rotten orange

TEST(Test944, DefaultTest)
{
    matrix2D input = {{2, 1, 1},
                      {1, 1, 0},
                      {0, 1, 1}};
    EXPECT_EQ(Solution().orangesRotting(input), 4);
}

TEST(Test944, MissingOneOrangeReturnImpossible)
{
    matrix2D input = {{2, 1, 1},
                      {0, 1, 1},
                      {1, 0, 1}};
    EXPECT_EQ(Solution().orangesRotting(input), -1);
}

TEST(Test944, NoOranges)
{
    matrix2D input = {{0, 2}};
    EXPECT_EQ(Solution().orangesRotting(input), 0);
}

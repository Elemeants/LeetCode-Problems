#include <gtest/gtest.h>
#include "main.h"

TEST(Test3195, Example1) {
  Grid2D grid = {
    {0, 1, 0},
    {1, 0, 1}
  };
  EXPECT_EQ(Solution().minimumArea(grid), 6);
}

TEST(Test3195, Example2) {
  Grid2D grid = {
    {1, 0},
    {0, 0}
  };
  EXPECT_EQ(Solution().minimumArea(grid), 1);
}

TEST(Test3195, Case0) {
  Grid2D grid = {
    {1}
  };
  EXPECT_EQ(Solution().minimumArea(grid), 1);
}

TEST(Test3195, Case1) {
  Grid2D grid = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
  };
  EXPECT_EQ(Solution().minimumArea(grid), 9);
}

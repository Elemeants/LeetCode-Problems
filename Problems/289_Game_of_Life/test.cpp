#include <gtest/gtest.h>
#include "main.h"

TEST(Test289, Example1) {
  Grid2D<int> grid = {
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 0}
  };
  Grid2D<int> expected = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0, 1, 0}
  };
  Solution().gameOfLife(grid);
  EXPECT_EQ(expected, grid);
}

TEST(Test289, Example2) {
  Grid2D<int> grid = {
    {1, 1},
    {1, 0},
  };
  Grid2D<int> expected = {
    {1, 1},
    {1, 1},
  };
  Solution().gameOfLife(grid);
  EXPECT_EQ(expected, grid);
}


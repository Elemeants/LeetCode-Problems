#include <gtest/gtest.h>

#include "main.h"

TEST(Test1091, Case1) {
  vector2D grid = {
    {0, 1},
    {1, 0}
  };
  EXPECT_EQ(Solution().shortestPathBinaryMatrix(grid), 2);
}

TEST(Test1091, Case2) {
  vector2D grid = {
    {0, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
  };
  EXPECT_EQ(Solution().shortestPathBinaryMatrix(grid), 4);
}

TEST(Test1091, Case3) {
  vector2D grid = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
  };
  EXPECT_EQ(Solution().shortestPathBinaryMatrix(grid), -1);
}

TEST(Test1091, Case4) {
  vector2D grid = {
    {0,1,1,0,0,0},
    {0,1,0,1,1,0},
    {0,1,1,0,1,0},
    {0,0,0,1,1,0},
    {1,1,1,1,1,0},
    {1,1,1,1,1,0}
  };
  EXPECT_EQ(Solution().shortestPathBinaryMatrix(grid), 14);
}

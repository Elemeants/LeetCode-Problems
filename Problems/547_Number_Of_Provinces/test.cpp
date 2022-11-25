#include <gtest/gtest.h>
#include "main.h"

TEST(Test547, Case1) {
  vector2D grid = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1}
  };
  EXPECT_EQ(Solution().findCircleNum(grid), 2);
}

TEST(Test547, Case2) {
  vector2D grid = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  };
  EXPECT_EQ(Solution().findCircleNum(grid), 3);
}

TEST(Test547, Case3) {
  vector2D grid = {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1}
  };
  EXPECT_EQ(Solution().findCircleNum(grid), 2);
}

TEST(Test547, Case4) {
  vector2D grid = {
    {1, 0, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 1, 1}
  };
  EXPECT_EQ(Solution().findCircleNum(grid), 1);
}

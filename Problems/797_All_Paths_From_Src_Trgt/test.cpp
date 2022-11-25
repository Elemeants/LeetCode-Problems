#include <gtest/gtest.h>
#include "main.h"

TEST(Test797, Case1) {
  vector2D input = {
    {1, 2},
    {3},
    {3},
    {}
  };
  vector2D expected = {
    {0, 1, 3},
    {0, 2, 3},
  };
  EXPECT_EQ(Solution().allPathsSourceTarget(input), expected);
}

TEST(Test797, Case2) {
  vector2D input = {
    {4, 3, 1},
    {3, 2, 4},
    {3},
    {4},
    {}
  };
  vector2D expected = {
    {0,4},
    {0,3,4},
    {0,1,3,4},
    {0,1,2,3,4},
    {0,1,4}
  };
  EXPECT_EQ(Solution().allPathsSourceTarget(input), expected);
}


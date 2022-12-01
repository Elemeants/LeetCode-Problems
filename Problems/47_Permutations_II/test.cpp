#include <gtest/gtest.h>
#include "main.h"

TEST(Test47, Case1) {
  std::vector<int> input = {1, 1, 2};
  vector2D expected = {
    {1, 1, 2},
    {1, 2, 1},
    {2, 1, 1},
  };

  EXPECT_EQ(Solution().permuteUnique(input), expected);
}

TEST(Test47, Case2) {
  std::vector<int> input = {1, 2, 3};
  vector2D expected = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}
  };

  EXPECT_EQ(Solution().permuteUnique(input), expected);
}

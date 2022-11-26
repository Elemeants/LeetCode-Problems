#include <gtest/gtest.h>
#include "main.h"

TEST(Test90, Case1) {
  std::vector<int> input  = {1, 2, 2};
  vector2D expected = {{},{1},{1,2},{1,2,2},{2},{2,2}};
  EXPECT_EQ(Solution().subsetsWithDup(input), expected);
}

TEST(Test90, Case2) {
  std::vector<int> input  = {0};
  vector2D expected = {{},{0}};
  EXPECT_EQ(Solution().subsetsWithDup(input), expected);
}

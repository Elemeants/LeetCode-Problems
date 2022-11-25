#include <gtest/gtest.h>
#include "main.h"

TEST(Test11, Case1) {
  std::vector<int> input = {1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(Solution().maxArea(input), 49);
}

TEST(Test11, Case2) {
  std::vector<int> input = {1,1};
  EXPECT_EQ(Solution().maxArea(input), 1);
}

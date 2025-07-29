#include <gtest/gtest.h>
#include "main.h"

TEST(Test2044, Example1) {
  const std::vector<int> nums = {3, 1};
  EXPECT_EQ(2, Solution().countMaxOrSubsets(nums));
}

TEST(Test2044, Example2) {
  const std::vector<int> nums = {2, 2, 2};
  EXPECT_EQ(7, Solution().countMaxOrSubsets(nums));
}

TEST(Test2044, Example3) {
  const std::vector<int> nums = {3, 2, 1, 5};
  EXPECT_EQ(6, Solution().countMaxOrSubsets(nums));
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Test740, Case1) {
  std::vector<int> nums = {3, 4, 2};
  EXPECT_EQ(Solution().deleteAndEarn(nums), 6);
}

TEST(Test740, Case2) {
  std::vector<int> nums = {2,2,3,3,3,4};
  EXPECT_EQ(Solution().deleteAndEarn(nums), 9);
}

TEST(Test740, Case3) {
  std::vector<int> nums = {3, 1};
  EXPECT_EQ(Solution().deleteAndEarn(nums), 4);
}

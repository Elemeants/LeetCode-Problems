#include <gtest/gtest.h>
#include "main.h"

TEST(Test209, Case1) {
  std::vector<int> input = {2,3,1,2,4,3};
  const int target = 7;
  EXPECT_EQ(Solution().minSubArrayLen(target, input), 2);
}

TEST(Test209, Case2) {
  std::vector<int> input = {1, 4, 4};
  const int target = 4;
  EXPECT_EQ(Solution().minSubArrayLen(target, input), 1);
}

TEST(Test209, Case3) {
  std::vector<int> input = {1,1,1,1,1,1,1,1};
  const int target = 11;
  EXPECT_EQ(Solution().minSubArrayLen(target, input), 0);
}

TEST(Test209, Case4) {
  std::vector<int> input = {1,2,3,4,5};
  const int target = 11;
  EXPECT_EQ(Solution().minSubArrayLen(target, input), 3);
}

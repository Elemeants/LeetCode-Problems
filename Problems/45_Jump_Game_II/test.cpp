#include <gtest/gtest.h>

#include "main.h"

TEST(Test45, Case1) {
  std::vector<int> input = {2, 3, 1, 1, 4};
  EXPECT_EQ(Solution().jump(input), 2);
}

TEST(Test45, Case2) {
  std::vector<int> input = {2, 3, 0, 1, 4};
  EXPECT_EQ(Solution().jump(input), 2);
}

TEST(Test45, Case3) {
  std::vector<int> input = {1, 2, 1, 1, 1};
  EXPECT_EQ(Solution().jump(input), 3);
}

TEST(Test45, Case4) {
  std::vector<int> input = {1,2,0,1};
  EXPECT_EQ(Solution().jump(input), 2);
}

TEST(Test45, Case5) {
  std::vector<int> input = {5,9,3,2,1,0,2,3,3,1,0,0};
  EXPECT_EQ(Solution().jump(input), 3);
}

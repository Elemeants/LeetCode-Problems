#include <gtest/gtest.h>
#include "main.h"

TEST(Test724, Case1) {
  std::vector<int> input = {1,7,3,6,5,6};
  EXPECT_EQ(Solution().pivotIndex(input), 3);
}

TEST(Test724, Case2) {
  std::vector<int> input = {1, 2, 3};
  EXPECT_EQ(Solution().pivotIndex(input), -1);
}

TEST(Test724, Case3) {
  std::vector<int> input = {2,1,-1};
  EXPECT_EQ(Solution().pivotIndex(input), 0);
}

TEST(Test724, Case4) {
  std::vector<int> input = {-1,-1,-1,1,1,1};
  EXPECT_EQ(Solution().pivotIndex(input), -1);
}

TEST(Test724, Case5) {
  std::vector<int> input = {0, 0, 0, 0, 1};
  EXPECT_EQ(Solution().pivotIndex(input), 4);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Test153, Case1) {
  const std::vector<int> input = {3,4,5,1,2};
  EXPECT_EQ(Solution().findMin(input), 1);
}

TEST(Test153, Case2) {
  const std::vector<int> input = {4,5,6,7,0,1,2};
  EXPECT_EQ(Solution().findMin(input), 0);
}

TEST(Test153, Case3) {
  const std::vector<int> input = {11,13,15,17};
  EXPECT_EQ(Solution().findMin(input), 11);
}

TEST(Test153, Case4) {
  const std::vector<int> input = {1};
  EXPECT_EQ(Solution().findMin(input), 1);
}

TEST(Test153, Case5) {
  const std::vector<int> input = {1, 2};
  EXPECT_EQ(Solution().findMin(input), 1);
}

TEST(Test153, Case6) {
  const std::vector<int> input = {2, 1};
  EXPECT_EQ(Solution().findMin(input), 1);
}
#include <gtest/gtest.h>
#include "main.h"

TEST(Test136, Case1) {
  std::vector<int> input = {2,2,1};
  EXPECT_EQ(Solution().singleNumber(input), 1);
}

TEST(Test136, Case2) {
  std::vector<int> input = {4,1,2,1,2};
  EXPECT_EQ(Solution().singleNumber(input), 4);
}

TEST(Test136, Case3) {
  std::vector<int> input = {1};
  EXPECT_EQ(Solution().singleNumber(input), 1);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Test560, Case1) {
  std::vector<int> input = {-3,2,-3,4,2};
  EXPECT_EQ(Solution().minStartValue(input), 5);
}

TEST(Test560, Case2) {
  std::vector<int> input = {1,2};
  EXPECT_EQ(Solution().minStartValue(input), 1);
}

TEST(Test560, Case3) {
  std::vector<int> input = {1,-2,-3};
  EXPECT_EQ(Solution().minStartValue(input), 5);
}

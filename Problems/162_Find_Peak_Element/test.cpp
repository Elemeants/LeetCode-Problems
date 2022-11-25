#include <gtest/gtest.h>
#include "main.h"

TEST(Test162, Case1) {
  const std::vector<int> input = {1,2,3,1};
  EXPECT_EQ(Solution().findPeakElement(input), 2);
}

TEST(Test162, Case2) {
  const std::vector<int> input = {1,2,1,3,5,6,4};
  EXPECT_EQ(Solution().findPeakElement(input), 5);
}

TEST(Test162, SizeOf1) {
  const std::vector<int> input = {1};
  EXPECT_EQ(Solution().findPeakElement(input), 0);
}

TEST(Test162, SizeOf2) {
  const std::vector<int> input = {1, 2};
  EXPECT_EQ(Solution().findPeakElement(input), 1);
}

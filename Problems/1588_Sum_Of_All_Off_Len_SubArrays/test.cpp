#include <gtest/gtest.h>

#include "main.h"

TEST(Test1588, Case1) {
  std::vector<int> input = {1, 4, 2, 5, 3};
  EXPECT_EQ(Solution().sumOddLengthSubarrays(input), 58);
}

TEST(Test1588, Case2) {
  std::vector<int> input = {1, 2};
  EXPECT_EQ(Solution().sumOddLengthSubarrays(input), 3);
}

TEST(Test1588, Case3) {
  std::vector<int> input = {10, 11, 12};
  EXPECT_EQ(Solution().sumOddLengthSubarrays(input), 66);
}

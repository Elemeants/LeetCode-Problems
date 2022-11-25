#include <gtest/gtest.h>
#include "main.h"

TEST(Test560, Case1) {
  const std::vector<int> input = {1, 1, 1};
  const int k = 2;
  EXPECT_EQ(Solution().subarraySum(input, k), 2);
}

TEST(Test560, Case2) {
  const std::vector<int> input = {1, 2, 3};
  const int k = 3;
  EXPECT_EQ(Solution().subarraySum(input, k), 2);
}

TEST(Test560, Case3) {
  const std::vector<int> input = {1, 2, 3, 2, 2, 3, 4, 5};
  const int k = 4;
  EXPECT_EQ(Solution().subarraySum(input, k), 2);
}

TEST(Test560, CaseWhenItShouldContinueCountingAfterFound) {
  const std::vector<int> input = {1, -1, 0};
  const int k = 0;
  EXPECT_EQ(Solution().subarraySum(input, k), 3);
}

TEST(Test560, NegativeK) {
  const std::vector<int> input = {1, -1, 0};
  const int k = -1;
  EXPECT_EQ(Solution().subarraySum(input, k), 2);
}

TEST(Test560, TimeExceedCase) {
  std::vector<int> input;
  input.resize(20000, 1);

  const int k = 150;
  EXPECT_EQ(Solution().subarraySum(input, k), 19851);
}

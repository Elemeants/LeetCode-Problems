#include <gtest/gtest.h>
#include "main.h"

TEST(Test416, Case1) {
  std::vector<int> input = {1,5,11,5};
  EXPECT_TRUE(Solution().canPartition(input));
}

TEST(Test416, Case2) {
  std::vector<int> input = {1,2,3,5};
  EXPECT_FALSE(Solution().canPartition(input));
}

TEST(Test416, SingleEntry) {
  std::vector<int> input = {1};
  EXPECT_FALSE(Solution().canPartition(input));
}

TEST(Test416, TwoEntryAndFailure) {
  std::vector<int> input = {1, 2};
  EXPECT_FALSE(Solution().canPartition(input));
}

TEST(Test416, TwoEntryAndSuccess) {
  std::vector<int> input = {2, 2};
  EXPECT_TRUE(Solution().canPartition(input));
}

TEST(Test416, MoreEntries) {
  std::vector<int> input = {1,3,4,4};
  EXPECT_FALSE(Solution().canPartition(input));
}

TEST(Test416, IsFailingWhy) {
  std::vector<int> input = {2,2,1,1};
  EXPECT_TRUE(Solution().canPartition(input));
}
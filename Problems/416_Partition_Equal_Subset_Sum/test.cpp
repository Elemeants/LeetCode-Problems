#include <gtest/gtest.h>

#include "main.h"

TEST(Test416, Case1) {
  std::vector<int> input = {1, 5, 11, 5};
  EXPECT_TRUE(Solution().canPartition(input));
}

TEST(Test416, Case2) {
  std::vector<int> input = {1, 2, 3, 5};
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
  std::vector<int> input = {1, 3, 4, 4};
  EXPECT_FALSE(Solution().canPartition(input));
}

TEST(Test416, IsFailingWhy) {
  std::vector<int> input = {2, 2, 1, 1};
  EXPECT_TRUE(Solution().canPartition(input));
}

TEST(Test416, LongTimeExecution) {
  std::vector<int> input = {
      80, 38, 97, 19, 81, 96, 70, 35, 12, 44, 33, 51, 78, 86, 31, 74, 94,
      54, 11, 91, 7,  90, 83, 12, 91, 67, 40, 80, 39, 87, 17, 49, 66, 56,
      15, 99, 95, 91, 22, 49, 14, 23, 18, 74, 22, 62, 14, 94, 75, 97, 45,
      32, 9,  21, 14, 70, 93, 14, 91, 6,  99, 12, 29, 32, 26, 33, 44, 24,
      82, 84, 95, 10, 91, 38, 23, 27, 64, 88, 83, 85, 7,  23, 62, 49, 60,
      67, 31, 55, 87, 42, 61, 4,  7,  10, 12, 8,  94, 9,  30, 59};
  EXPECT_TRUE(Solution().canPartition(input));
}
TEST(Test416, LongTimeExecution2) {
  std::vector<int> input = {
      61, 96, 15, 73, 64, 57, 7,  25, 52, 68, 59, 53, 72, 6,  22, 76, 12,
      8,  29, 99, 1,  77, 57, 39, 95, 51, 44, 61, 67, 35, 70, 96, 46, 91,
      51, 38, 33, 80, 45, 68, 20, 9,  6,  74, 4,  89, 10, 58, 95, 38, 85,
      62, 13, 23, 2,  5,  73, 45, 17, 3,  62, 64, 65, 50, 21, 30, 36, 60,
      43, 57, 25, 63, 47, 72, 35, 94, 79, 88, 2,  57, 60, 32, 96, 66, 90,
      5,  48, 74, 45, 88, 24, 3,  38, 80, 50, 45, 83, 66, 74, 91};
  EXPECT_TRUE(Solution().canPartition(input));
}
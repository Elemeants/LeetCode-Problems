#include <gtest/gtest.h>

#include "main.h"

TEST(Test739, Case1) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(Solution().dailyTemperatures(temperatures), expected);
}

TEST(Test739, Case2) {
  std::vector<int> temperatures = {30, 40, 50, 60};
  std::vector<int> expected = {1, 1, 1, 0};
  EXPECT_EQ(Solution().dailyTemperatures(temperatures), expected);
}

TEST(Test739, Case3) {
  std::vector<int> temperatures = {30, 60, 90};
  std::vector<int> expected = {1, 1, 0};
  EXPECT_EQ(Solution().dailyTemperatures(temperatures), expected);
}

TEST(Test739, Case4) {
  std::vector<int> temperatures = {34, 80, 80, 34, 34, 80, 80, 80, 80, 34};
  std::vector<int> expected     = {1, 0, 0, 2, 1, 0, 0, 0, 0, 0};
  EXPECT_EQ(Solution().dailyTemperatures(temperatures), expected);
}

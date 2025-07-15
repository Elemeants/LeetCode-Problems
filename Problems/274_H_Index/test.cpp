#include <gtest/gtest.h>
#include "main.h"

TEST(Problem274, Example1) {
  std::vector<int> citations = {3, 0, 6, 1, 5};
  EXPECT_EQ(Solution().hIndex(citations), 3);
}

TEST(Problem274, Example2) {
  std::vector<int> citations = {1, 3, 1};
  EXPECT_EQ(Solution().hIndex(citations), 1);
}

TEST(Problem274, Case1) {
  std::vector<int> citations = {0, 0, 2};
  EXPECT_EQ(Solution().hIndex(citations), 1);
}

TEST(Problem274, Case2) {
  std::vector<int> citations = {0, 3, 3};
  EXPECT_EQ(Solution().hIndex(citations), 2);
}

TEST(Problem274, Case3) {
  std::vector<int> citations = {11, 15};
  EXPECT_EQ(Solution().hIndex(citations), 2);
}

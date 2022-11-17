#include <gtest/gtest.h>
#include "main.h"

TEST(Test338, BaseCase) {
  std::vector<int> expected = {0};
  EXPECT_EQ(Solution().countBits(0), expected);
}

TEST(Test338, SimpleCase) {
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(Solution().countBits(1), expected);
}

TEST(Test338, RecursiveCase) {
  std::vector<int> expected = {0, 1, 1};
  EXPECT_EQ(Solution().countBits(2), expected);
}

TEST(Test338, Case1) {
  std::vector<int> expected = {0, 1, 1, 2, 1, 2};
  EXPECT_EQ(Solution().countBits(5), expected);
}

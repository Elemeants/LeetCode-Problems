#include <gtest/gtest.h>

#include "main.h"

TEST(Test438, Case1) {
  std::vector<int> expected = {0, 6};
  EXPECT_EQ(Solution().findAnagrams("cbaebabacd", "abc"), expected);
}

TEST(Test438, Case2) {
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(Solution().findAnagrams("abab", "ab"), expected);
}

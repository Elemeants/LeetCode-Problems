#include <gtest/gtest.h>
#include "main.h"

TEST(Test1544, Case1) {
  std::string input = "leEeetcode";
  std::string expected = "leetcode";
  EXPECT_EQ(Solution().makeGood(input), expected);
}

TEST(Test1544, Case2) {
  std::string input = "abBAcC";
  std::string expected = "";
  EXPECT_EQ(Solution().makeGood(input), expected);
}

TEST(Test1544, Case3) {
  std::string input = "s";
  std::string expected = "s";
  EXPECT_EQ(Solution().makeGood(input), expected);
}

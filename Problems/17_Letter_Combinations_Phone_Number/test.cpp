#include <gtest/gtest.h>
#include "main.h"

TEST(Test17, Case1) {
  const std::vector<std::string> expected = {"ad","ae","af","bd","be","bf","cd","ce","cf"};

  EXPECT_EQ(Solution().letterCombinations("23"), expected);
}

TEST(Test17, Case2) {
  const std::vector<std::string> expected = {};

  EXPECT_EQ(Solution().letterCombinations(""), expected);
}

TEST(Test17, Case3) {
  const std::vector<std::string> expected = {"a", "b", "c"};

  EXPECT_EQ(Solution().letterCombinations("2"), expected);
}

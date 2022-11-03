#include <gtest/gtest.h>
#include "main.h"

TEST(Test784, DefaultTest) {
  std::vector<std::string> expected = {"a1b2", "A1b2", "a1B2", "A1B2"};
  EXPECT_EQ(Solution().letterCasePermutation("a1b2"), expected);
}

TEST(Test784, OneEntry) {
  std::vector<std::string> expected = {"3z4", "3Z4"};
  EXPECT_EQ(Solution().letterCasePermutation("3z4"), expected);
}

TEST(Test784, NoLettersOnlyDigits) {
  std::vector<std::string> expected = {"123456"};
  EXPECT_EQ(Solution().letterCasePermutation("123456"), expected);
}

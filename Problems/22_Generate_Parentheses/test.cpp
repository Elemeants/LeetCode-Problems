#include <gtest/gtest.h>

#include "main.h"

TEST(Test22, Case1) {
  std::vector<std::string> expected = {"()()()", "(()())", "()(())", "(())()",
                                       "((()))"};
  EXPECT_EQ(Solution().generateParenthesis(3), expected);
}

TEST(Test22, Case2) {
  std::vector<std::string> expected = {"()"};
  EXPECT_EQ(Solution().generateParenthesis(1), expected);
}

TEST(Test22, Case3) {
  std::vector<std::string> expected = {"()()", "(())"};
  EXPECT_EQ(Solution().generateParenthesis(2), expected);
}

TEST(Test22, Case4) {
  std::vector<std::string> expected = {
      "(((())))", "((()()))", "((())())", "((()))()", "(()(()))",
      "(()()())", "(()())()", "(())(())", "(())()()", "()((()))",
      "()(()())", "()(())()", "()()(())", "()()()()"};
  std::vector<std::string> result = Solution().generateParenthesis(4);

  EXPECT_EQ(result.size(), expected.size());
  for (const std::string& result : result) {
    EXPECT_TRUE(std::find(expected.begin(), expected.end(), result) != expected.end());
  }
}

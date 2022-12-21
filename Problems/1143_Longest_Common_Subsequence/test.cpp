#include <gtest/gtest.h>
#include "main.h"

class SolutionTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SolutionTest, TestLongestCommonSubsequence) {
  // Test empty strings
  EXPECT_EQ(solution.longestCommonSubsequence("", ""), 0);

  // Test one empty string
  EXPECT_EQ(solution.longestCommonSubsequence("abc", ""), 0);
  EXPECT_EQ(solution.longestCommonSubsequence("", "abc"), 0);

  // Test strings with no common characters
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "def"), 0);

  // Test strings with common characters
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "abc"), 3);
  EXPECT_EQ(solution.longestCommonSubsequence("abcdef", "abc"), 3);
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "abcdef"), 3);
  EXPECT_EQ(solution.longestCommonSubsequence("abcdef", "abcdef"), 6);
  EXPECT_EQ(solution.longestCommonSubsequence("abcdef", "bcd"), 3);
  EXPECT_EQ(solution.longestCommonSubsequence("oxcpqrsvwf", "shmtulqrypy"), 2);
  EXPECT_EQ(solution.longestCommonSubsequence("ezupkr", "ubmrapg"), 2);
  EXPECT_EQ(solution.longestCommonSubsequence("hofubmnylkra", "pqhgxgdofcvmr"), 5);
  EXPECT_EQ(solution.longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd"), 4);
}
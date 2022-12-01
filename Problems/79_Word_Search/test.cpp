#include <gtest/gtest.h>

#include "main.h"

TEST(Test79, Case1) {
  matrix2D board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  std::string word = "ABCCED";
  EXPECT_TRUE(Solution().exist(board, word));
}

TEST(Test79, Case2) {
  matrix2D board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  std::string word = "SEE";
  EXPECT_TRUE(Solution().exist(board, word));
}

TEST(Test79, Case3) {
  matrix2D board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  std::string word = "ABCB";
  EXPECT_FALSE(Solution().exist(board, word));
}

TEST(Test79, Case4) {
  matrix2D board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'E', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  std::string word = "ABCESEEEFS";
  EXPECT_TRUE(Solution().exist(board, word));
}

TEST(Test79, Case5) {
  matrix2D board = {
      {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A'}};
  std::string word = "AAAAAAAAAAAABAA";
  EXPECT_FALSE(Solution().exist(board, word));
}

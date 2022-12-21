#include <gtest/gtest.h>
#include "main.h"

TEST(Test130, Case1) {
  matrix2D board = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'},
  };
  const matrix2D expected = {
    {'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'X', 'X'},
  };
  Solution().solve(board);
  EXPECT_EQ(board, expected);
}

TEST(Test130, Case2) {
  matrix2D board = {
    {'X'}
  };
  const matrix2D expected = {
    {'X'}
  };
  Solution().solve(board);
  EXPECT_EQ(board, expected);
}

TEST(Test130, Case3) {
  matrix2D board = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'X'},
  };
  const matrix2D expected = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'X'},
  };
  Solution().solve(board);
  EXPECT_EQ(board, expected);
}

TEST(Test130, Case4) {
  matrix2D board = {
    {'O'}
  };
  const matrix2D expected = {
    {'O'}
  };
  Solution().solve(board);
  EXPECT_EQ(board, expected);
}

//
// 79. Word Search
//
#pragma once

#include <deque>
#include <string>
#include <vector>

using matrix2D = std::vector<std::vector<char>>;

class Solution {
 public:
  bool exist(matrix2D& board, std::string word) {
    // Look for any starting character on the word
    for (size_t y = 0; y < board.size(); ++y) {
      for (size_t x = 0; x < board[0].size(); ++x) {
        if (wrapperSearch(board, word, y, x)) {
          return true;
        }
      }
    }

    return false;
  }

  bool wrapperSearch(matrix2D& board, std::string word, const int y,
                     const int x) {
    bool found = false;
    searchWord(board, word, 0, y, x, found);
    return found;
  }

  void searchWord(matrix2D& board, std::string word,
                  const size_t letterIndex, const int y, const int x,
                  bool& found) {
    const int x_lower = 0;
    const int y_lower = 0;
    const int x_high = board[0].size() - 1;
    const int y_high = board.size() - 1;

    if (letterIndex == word.size()) {
      found = true;
      return;
    }

    if (x < x_lower || y < y_lower || x > x_high || y > y_high ||
        board[y][x] != word[letterIndex]) {
      return;
    }

    char saved = board[y][x];
    board[y][x] = '0';
    searchWord (board, word, letterIndex + 1, y + 1, x, found);
    searchWord (board, word, letterIndex + 1, y - 1, x, found);
    searchWord (board, word, letterIndex + 1, y, x + 1, found);
    searchWord (board, word, letterIndex + 1, y, x - 1, found);
    board[y][x] = saved;
  }
};

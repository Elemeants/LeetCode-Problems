//
// 130. Surrounded Regions
//
#pragma once

#include <vector>

using matrix2D = std::vector<std::vector<char>>;

class Solution {
 public:
  void solve(matrix2D& board) {
    convertNodesOnBorders(board);
    flipNodes(board, 'O', 'X');
    flipNodes(board, '0', 'O');
  }

 private:
  void convertNodesOnBorders(matrix2D& board) {
    const size_t size_x = board[0].size();
    const size_t size_y = board.size();

    // First col
    for (size_t y = 0; y < size_y; ++y) {
      if (board[y][0] == 'O') {
        touchAdjacentNodes(board, y, 0);
      }
    }

    // First row
    for (size_t x = 0; x < size_x; ++x) {
      if (board[0][x] == 'O') {
        touchAdjacentNodes(board, 0, x);
      }
    }

    // Last row
    for (size_t x = 0; x < size_x; ++x) {
      if (board[size_y - 1][x] == 'O') {
        touchAdjacentNodes(board, size_y - 1, x);
      }
    }

    // Last col
    for (size_t y = 0; y < size_y; ++y) {
      if (board[y][size_x - 1] == 'O') {
        touchAdjacentNodes(board, y, size_x - 1);
      }
    }
  }

  void flipNodes(matrix2D& board, const char from, const char to) {
    const size_t size_x = board[0].size();
    const size_t size_y = board.size();
    
    for (size_t y = 0; y < size_y; ++y) {
      for (size_t x = 0; x < size_x; ++x) {
        if (board[y][x] == from) {
          board[y][x] = to;
        }
      }
    }
  }

  void touchAdjacentNodes(matrix2D& board, int y, int x) {
    const int size_x = board[0].size();
    const int size_y = board.size();
    if (y < 0 || x < 0 || y >= size_y || x >= size_x || board[y][x] != 'O') {
      return;
    }

    board[y][x] = '0';
    touchAdjacentNodes(board, y, x - 1);
    touchAdjacentNodes(board, y, x + 1);
    touchAdjacentNodes(board, y - 1, x);
    touchAdjacentNodes(board, y + 1, x);
  }
};

//
// 289. Game of Life
//
#pragma once

#include <vector>
#include <utility>
#include <iostream>

template <typename T>
using Grid2D = std::vector<std::vector<T>>;

typedef enum {
  DEAD = 0,
  LIVE = 1,
} CellStatus_e;

class Solution {
  void initializeBuffer(Grid2D<int>& board, Grid2D<int>& buffer) {
    for (size_t y = 0; y < board.size(); y++) {
      std::vector<int> row;
      for (size_t x = 0; x < board[y].size(); x++) {
        row.push_back(0);
      }
      buffer.push_back(row);
    }
  }

  CellStatus_e calculateNextCellState(Grid2D<int>& board,
                                      std::pair<size_t, size_t> pos) {
    const size_t living_cells = countLivingCells(board, pos);
    const bool isPosAlive     = board[pos.first][pos.second] == LIVE;

    if (!isPosAlive) {
      if (living_cells != 3) {
        return DEAD;
      }
      return LIVE;
    }

    if (living_cells < 2) {
      return DEAD;
    }
    if (living_cells <= 3) {
      return LIVE;
    }

    return DEAD;
  }

  size_t countLivingCells(Grid2D<int>& board, std::pair<size_t, size_t> pos) {
    const std::vector<std::pair<size_t, size_t>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
    };
    const std::pair<size_t, size_t> board_size = std::make_pair(board.size(), board[0].size());

    size_t live_cells = 0;
    for (size_t dirs_idx = 0; dirs_idx < dirs.size(); dirs_idx ++) {
      const std::pair<size_t, size_t>& dir = dirs[dirs_idx];
      const std::pair<size_t, size_t> new_pos = std::make_pair(pos.first + dir.first, pos.second + dir.second);
      if (new_pos.first < 0 || new_pos.first >= board_size.first || new_pos.second < 0 || new_pos.second >= board_size.second) {
        continue;
      }

      if (board[new_pos.first][new_pos.second] == (int)DEAD) {
        continue;
      }

      live_cells++;
    }
    return live_cells;
  }

  void copyInternalBufferToBoard(Grid2D<int>& board, Grid2D<int>& buffer) {
    for (size_t y = 0; y < board.size(); y++) {
      for (size_t x = 0; x < board[y].size(); x++) {
        board[y][x] = buffer[y][x];
      }
    }
  }

 public:
  void gameOfLife(Grid2D<int>& board) {
    Grid2D<int> buffer;
    initializeBuffer(board, buffer);

    for (size_t y = 0; y < board.size(); y++) {
      for (size_t x = 0; x < board[y].size(); x++) {
        buffer[y][x] = calculateNextCellState(board, std::make_pair(y, x));
      }
    }

    copyInternalBufferToBoard(board, buffer);
  }
};

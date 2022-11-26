//
// 304. Range Sum Query 2D - Immutable
//
#pragma once

#include <vector>

using vector2D = std::vector<std::vector<int>>;

class NumMatrix {
  const vector2D& original;
  vector2D prefixSums;
 public:
  NumMatrix(const vector2D& matrix) : original(matrix), prefixSums(matrix) {
    for (size_t y = 1; y < matrix.size(); y++) {
      prefixSums[y][0] += prefixSums[y - 1][0];
    }
    for (size_t x = 1; x < matrix[0].size(); x++) {
      prefixSums[0][x] += prefixSums[0][x - 1];
    }

    for (size_t y = 1; y < matrix.size(); y++) {
      for (size_t x = 1; x < matrix[0].size(); x++) {
        prefixSums[y][x] =  original[y][x] +
                            prefixSums[y - 1][x] +
                            prefixSums[y][x - 1] -
                            prefixSums[y - 1][x - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 < 0 || col1 < 0 || row2 >= (int)prefixSums.size() || col2 >= (int)prefixSums[0].size()) {
      return 0;
    }

    int acc = prefixSums[row2][col2];
    if (row1 > 0) {
      acc -= prefixSums[row1 - 1][col2];
    }
    if (col1 > 0) {
      acc -= prefixSums[row2][col1 - 1];
    }
    if (row1 > 0 && col1 > 0) {
      acc += prefixSums[row1 - 1][col1 - 1];
    }
    return acc;
  }

  void printGrid(const vector2D& grid) {
    const int x_high = grid.size();
    const int y_high = grid[0].size();

    for (int x = 0; x < x_high; ++x) {
      for (int y = 0; y < y_high; ++y) {
        std::cout << " " << grid[x][y];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
};

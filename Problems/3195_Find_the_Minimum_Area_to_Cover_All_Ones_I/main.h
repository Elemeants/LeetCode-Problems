//
// 3195. Find the Minimum Area to Cover All Ones I
//
#pragma once

//
// So my initial idea is to find all one's, so I can save the coords
// in an array.
// Then get the lowest / largest of each axis.
// and multiply them.
//
// 0 1 0
// 1 0 1
// 0 0 1
//
// For the given example we will have an array of:
// [(0, 1), (1, 0), (1, 2), (2, 2)]
// -> x Axis (0, 2) distance: 3
// -> y Axis (0, 2) distance: 3
// then we multiply the distances = 3 * 3 = 9
//
// 0 0 0
// 0 0 1
// 0 1 1
//
// For the given example we will have an array of:
// [(1, 2), (2, 1), (2, 2)]
// -> x Axis (1, 2) distance: 2
// -> y Axis (1, 2) distance: 2
// then we multiply the distances = 2 * 3 = 6
//

#include <iostream>
#include <utility>
#include <vector>

using Grid2D = std::vector<std::vector<int>>;

class Solution {
 public:
  int minimumArea(Grid2D& grid) {
    const size_t rows = grid.size();
    const size_t cols = grid[0].size();
    std::pair<size_t, size_t> lowest = std::make_pair(10001, 10001);
    std::pair<size_t, size_t> highest = std::make_pair(0, 0);

    // Find all one's
    for (size_t y = 0; y < rows; y++) {
      for (size_t x = 0; x < cols; x++) {
        if (grid[y][x] == 0) {
          continue;
        }

        if (y < lowest.first) {
          lowest.first = y;
        }
        if (y > highest.first) {
          highest.first = y;
        }

        if (x < lowest.second) {
          lowest.second = x;
        }
        if (x > highest.second) {
          highest.second = x;
        }
      }
    }

    const int area = (highest.first - lowest.first + 1) *
                     (highest.second - lowest.second + 1);

    return area;
  }
};

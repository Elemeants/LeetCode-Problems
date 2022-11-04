//
// 120. Triangle
//
#pragma once

#include <vector>
#include <algorithm>

class Solution
{
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle)
  {
    const size_t totalLevels = (triangle.size());
    for (size_t level = 1; level < totalLevels; ++level) {
      triangle[level][0] += triangle[level - 1][0];
      for (size_t col = 1; col < triangle[level].size(); ++col) {
        if (col == (triangle[level].size() - 1)) {
          triangle[level][col] += triangle[level - 1][col - 1];
        } else {
          triangle[level][col] += std::min(triangle[level - 1][col], triangle[level - 1][col - 1]);
        }
      }
    }

    return *std::min_element(triangle[totalLevels - 1].begin(), triangle[totalLevels - 1].end());
  }
};

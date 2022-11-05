//
// 835. Image Overlap
//
#pragma once

#include <vector>
#include <algorithm>

using binaryMatrix = std::vector<std::vector<int>>;

class Solution
{
public:
  int largestOverlap(binaryMatrix &img1, binaryMatrix &img2)
  {
    const int side_size = (int)img1.size();
    if (side_size == 0) { return 0; }
    else if (side_size == 1) { return img1[0][0] & img2[0][0]; }

    size_t maxOverlap = 0;
    for (int i = -side_size; i < side_size; ++i) {
      for (int j = -side_size; j < side_size; ++j) {
        const size_t overlap = countOverlap(img1, img2, i, j);
        if (overlap > maxOverlap) { maxOverlap = overlap; }
      }
    }
    return maxOverlap;
  }

  size_t countOverlap(const binaryMatrix &img1, const binaryMatrix &img2, const int offset_x, const int offset_y)
  {
    size_t overlapCount = 0;
    size_t side_size = img1.size();
    for (size_t i = 0; i < side_size; ++i) {
      int _x = i + offset_x;
      if (_x < 0 || _x >= (int)side_size) { continue; }
      for (size_t j = 0; j < side_size; ++j) {
        int _y = j + offset_y;
        if (_y < 0 || _y >= (int)side_size) { continue; }
        overlapCount += (img1[i][j] & img2[_x][_y]);
      }
    }
    return overlapCount;
  }
};

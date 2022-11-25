//
// 74. Search a 2D Matrix
//
#pragma once

#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution
{
  int binarySearch(const std::vector<int> &matrix, int target, int left, int right)
  {
    while ((left + 1) < right)
    {
      const int mid = left + ((right - left) / 2);
      const int mid_val = matrix[mid];
      if (mid_val == target)
        return mid;
      else if (mid_val < target)
        left = mid;
      else
        right = mid;
    }
    if (matrix[left] == target)
      return left;
    if (matrix[right] == target)
      return right;
    return -1;
  }

  int foundRowThatMayContainTheValue(const vector2D &matrix, int target) {
    int left = 0;
    int right = matrix.size() - 1;
    while (left <= right) {
      const int mid = left + ((right - left) / 2);
      if (matrix[mid][0] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return right;
  }

public:
  bool searchMatrix(const vector2D &matrix, int target)
  {
    // Found row index near to the target
    int row = foundRowThatMayContainTheValue(matrix, target);
    if (row == -1) {
      return false;
    }
    return binarySearch(matrix[row], target, 0, matrix[row].size() - 1) != -1;
  }
};

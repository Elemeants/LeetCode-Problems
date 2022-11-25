//
// 153. Find Minimum in Rotated Sorted Array
//
#pragma once

#include <vector>

class Solution
{
  int findPivotIndexOfRotatedArray(const std::vector<int>& array) {
    int left = 0;
    int right = array.size() - 1;
    if (right == left) { return right; }
    int back_value = array[right];
    while (left <= right) {
      const int mid = left + ((right - left) / 2);
      const int mid_val = array[mid];
      if (mid_val < back_value) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return std::min(right + 1, (int)array.size() - 1);
  }
public:
  int findMin(const std::vector<int> &nums)
  {
    int pivotIndex = findPivotIndexOfRotatedArray(nums);
    return nums[pivotIndex];
  }
};
//
// 162. Find Peak Element
//
#pragma once

#include <vector>
#include <iostream>

class Solution
{
public:
  int findPeakElement(const std::vector<int> &nums)
  {
    int left = 0;
    int right = nums.size() - 1;

    if (right == left) {
      return right;
    }

    while (left <= right) {
      const int mid = left + ((right - left) / 2);
      if (isPositiveTangent(nums, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return std::min(right + 1, (int)nums.size() - 1);
  }

  int isPositiveTangent (const std::vector<int> &nums, int index) {
    const int curr = nums[index];
    if (index == ((int)nums.size() - 1)) {
      const int prev = std::max(index - 1, 0);
      return nums[prev] > curr;
    } else {
      const int next = std::min(index + 1, (int)nums.size() - 1);
      return curr > nums[next];
    }
  }
};
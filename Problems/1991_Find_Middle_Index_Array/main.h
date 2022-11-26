//
// 1991. Find the Middle Index in Array
//
#pragma once

#include <vector>

class Solution {
 public:
  int findMiddleIndex(std::vector<int>& nums) {
    const int nums_size = nums.size();
    if (nums_size == 1) {
      return 0;
    }

    int acc_left  = 0;
    int acc_right = 0;
    int pivotIndex = 0;

    for (int i = 1; i < nums_size; i++) {
      acc_right += nums[i];
    }

    for (; pivotIndex < nums_size; pivotIndex++) {
      if (acc_left == acc_right) {
        return pivotIndex;
      }
      acc_left += nums[pivotIndex];
      if (pivotIndex < (nums_size - 1)) {
        acc_right -= nums[pivotIndex + 1];
      }
    }

    return -1;
  }
};

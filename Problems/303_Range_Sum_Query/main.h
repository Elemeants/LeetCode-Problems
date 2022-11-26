//
// 303. Range Sum Query - Immutable
//
#pragma once

#include <vector>

class NumArray {
  const std::vector<int>& nums;

 public:
  NumArray(std::vector<int>& nums) : nums(nums) {}

  int sumRange(int left, int right) {
    int acc = 0;
    while (left <= right) {
      acc += nums[left++];
    }
    return acc;
  }
};

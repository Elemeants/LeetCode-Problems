//
// 213. House Robber II
//
#pragma once

#include <vector>

//
// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed.
// All houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, and it
// will automatically contact the police if two adjacent houses were
// broken into on the same night.
//
// Given an integer array nums representing the amount of money of each
// house, return the maximum amount of money you can rob tonight without
// alerting the police.
//
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
// because they are adjacent houses.
//
class Solution {
 public:
  int rob(std::vector<int>& nums) {
    const size_t nums_size = nums.size();
    if (nums_size == 1)
    {
      return nums[0];
    }

    return std::max(_rob(nums, 0, nums_size - 1), _rob(nums, 1, nums_size));
  }

 private:
  int _rob(std::vector<int>& nums, size_t start, size_t end) {
    int prev      = 0;
    int prev_prev = 0;
    for (size_t index = start; index < end; ++index) {
      const int& houseValue = nums[index];
      int tmp = prev;
      prev = std::max(houseValue + prev_prev, prev);
      prev_prev = tmp;
    }

    return prev;
  }
};

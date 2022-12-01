//
// 416. Partition Equal Subset Sum
//
#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  bool canPartition(std::vector<int> &nums)
  {
    const size_t nums_size = nums.size();
    const int total_sum = sum(nums);
    if (nums_size == 1 || total_sum % 2 != 0) {
      return false;
    } else if (nums_size == 2) {
      return nums[0] == nums[1];
    }

    const int mid_sum = total_sum / 2;
    std::unordered_set<int> sums;
    sums.insert(0);

    for (const int& i : nums) {
      std::unordered_set<int> crr = sums;
      for (const int& j : crr) {
        const int v = i + j;
        sums.insert(v);
        if (v == mid_sum) {
          return true;
        }
      }
    }

    return false;
  }

  int sum(const std::vector<int> &nums) {
    int acc = 0;
    for (const int& i : nums) {
      acc += i;
    }
    return acc;
  }
};
//
// 53. Maximum Subarray
//
#pragma once

#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int totalMax = INT32_MIN;
    int localMax = 0;

    for (const int &num : nums) {
      localMax = std::max(num, num + localMax);
      totalMax = std::max(totalMax, localMax);
    }

    return totalMax;
  }
};

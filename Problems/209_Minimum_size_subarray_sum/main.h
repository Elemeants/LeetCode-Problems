//
// 209. Minimum Size Subarray Sum
//
#pragma once

#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int left = 0;
    int right = 0;
    int min_len = nums.size() + 1;
    int acc = 0;
    for (; right < (int)nums.size(); right++) {
      acc += nums[right];

      if (acc >= target) {
        min_len = std::min(min_len, (right - left) + 1);
      }

      while (left < right && acc > target) {
        acc -= nums[left++];
        if (acc >= target) {
          min_len = std::min(min_len, (right - left) + 1);
        }
      }
    }

    if (min_len == ((int)nums.size() + 1)) {
      min_len = 0;
    } 

    return min_len;
  }
};

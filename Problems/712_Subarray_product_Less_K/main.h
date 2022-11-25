//
// 713. Subarray Product Less Than K
//
#pragma once

#include <iostream>
#include <vector>

class Solution {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    int count = 0;
    int acc = 1;
    size_t tail = 0;
    for (size_t head = 0; head < nums.size(); ++head) {
      acc *= nums[head];
      while (tail < head && acc >= k) {
        acc /= nums[tail++];
      }
      if (acc < k) {
        count += (head - tail) + 1;
      }
    }

    return count;
  }
};
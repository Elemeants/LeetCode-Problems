//
// 55. Jump Game
//
#pragma once

#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int>& nums) {
    int safeIndex = (int)nums.size() - 1;

    for (int index = (safeIndex - 1); index >= 0; index--) {
      const int distance = safeIndex - index;
      if (nums[index] >= distance) {
        safeIndex = index;
      }
    }

    return safeIndex == 0;
  }
};

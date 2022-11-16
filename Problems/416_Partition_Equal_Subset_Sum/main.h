//
// 416. Partition Equal Subset Sum
//
#pragma once

#include <vector>
#include <iostream>

class Solution
{
public:
  bool canPartition(std::vector<int> &nums)
  {
    const size_t nums_size = nums.size();
    if (nums_size == 1) {
      return false;
    } else if (nums_size == 2) {
      return nums[0] == nums[1];
    }

    std::sort(nums.begin(), nums.end());

    auto it = nums.begin();
    auto itEnd = nums.end();

    int accRight  = 0;
    int accLeft   = 0;
    while (it < itEnd) {
      if (accRight <= accLeft) {
        accRight += *it;
        it ++;
      } else if (accRight > accLeft) {
        itEnd--;
        accLeft += *itEnd;
      }
      std::cout << "accLeft: " << accLeft << " accRight: " << accRight << std::endl;
    }

    return accRight == accLeft;
  }
};
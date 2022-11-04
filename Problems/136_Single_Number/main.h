//
// 136. Single Number
//
#pragma once

#include <vector>

class Solution
{
public:
  int singleNumber(std::vector<int> &nums)
  {
    std::uint32_t k = 0;
    for (const int& num : nums) {
      k ^= num;
    }
    return k;
  }
};
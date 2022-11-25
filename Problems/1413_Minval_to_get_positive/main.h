//
// 1413. Minimum Value to Get Positive Step by Step Sum
//
#pragma once

#include <vector>
#include <iostream>

class Solution
{
public:
  int minStartValue(std::vector<int> &nums)
  {
    int prefix = 1;
    int acc = prefix;
    for (const int & i : nums) {
      acc += i;
      if (acc < 1) {
        prefix += 1 - acc;
        acc = 1;
      }
    }

    return prefix;
  }
};
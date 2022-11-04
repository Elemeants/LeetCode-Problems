//
// 70. Climbing Stairs
//
#pragma once

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n < 2)
    {
      return 1;
    }
    int acc = 0;
    int prev = 1;
    int prev_prev = 1;
    for (int i = 0; i <= (n - 2); i++) {
      acc = prev + prev_prev;
      prev_prev = prev;
      prev = acc;
    }
    return acc;
  }
};

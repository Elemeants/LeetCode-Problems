//
// 231. Power of Two
//
#pragma once

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    return n <= 0 ? false : (n & (n - 1)) == 0;
  }
};

//
// 191. Number of 1 Bits
//
#pragma once

#define BIT_0(i) (i & 0b1)

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int no_of_1s = BIT_0(n);
    while ((n >>= 1) != 0) no_of_1s += BIT_0(n);
    return no_of_1s;
  }
};

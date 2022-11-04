//
// 190. Reverse Bits
//
#pragma once

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint8_t bit = 31;
    int32_t v = (n & 0b1) << (bit --);
    while ((n >>= 1) != 0) v |= (n & 0b1) << (bit --);
    return v;
  }
};
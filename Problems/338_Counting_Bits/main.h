//
// 338. Counting Bits
//
#pragma once

#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
      std::vector<int> result;
      result.resize(n + 1);
      for (int i = 0; i <= n; i++) {
        result[i] = getNoOf1sOnInt(i);
      }
      return result;
    }

    int getNoOf1sOnInt(int n) {
      int no_of_1s = (n & 0b1);
      while ((n >>= 1) != 0) no_of_1s += (n & 0b1);
      return no_of_1s;
    }
};

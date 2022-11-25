//
// 560. Subarray Sum Equals K
//
#pragma once

#include <vector>
#include <map>

class Solution
{
public:
  int subarraySum(const std::vector<int> &nums, const int k)
  {
    std::map<int, int> table;

    int count = 0;
    int acc = 0;

    for (const int& i : nums) {
      acc += i;

      if (acc == k) {
        count++;
      }

      if (table.count(acc - k) > 0) {
        count += table[acc - k];
      }

      if (table.count(acc) > 0) {
        table[acc] ++;
      } else {
        table.insert(std::make_pair(acc, 1));
      }
    }

    return count;
  }
};
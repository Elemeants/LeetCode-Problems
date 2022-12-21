//
// 740. Delete and Earn
//
#pragma once

#include <vector>
#include <map>

class Solution {
 public:
  int deleteAndEarn(std::vector<int>& nums) {
    std::map<int, int> prefixedSum;
    for (const int& i : nums) {
      prefixedSum[i] += i;
    }

    return max(prefixedSum);
  }

 private:
  int max(std::map<int, int>& sums) {
    std::pair<int, int> minmax = std::make_pair(sums.begin()->first, sums.rbegin()->first);
    int prev      = 0;
    int prev_prev = 0;
    for (int i = minmax.first; i <= minmax.second; i++) {
      int tmp = prev;
      int sum_i = sums.find(i) != sums.end() ? sums[i] : 0;
      prev = std::max(sum_i + prev_prev, prev);
      prev_prev = tmp;
    }
    return prev;
  }
};

//
// 39. Combination Sum
//
#pragma once

#include <iostream>
#include <vector>
#include <map>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  vector2D combinationSum(std::vector<int>& candidates, int target) {
    vector2D result;
    std::vector<int> helper;

    std::sort(candidates.begin(), candidates.end());

    combineRecursive(candidates, result, helper, 0, target);

    return result;
  }

  void combineRecursive(const std::vector<int>& candidates,
                        vector2D& result,
                        std::vector<int>& backTracking,
                        int prevIndex,
                        int target) {
    if (target == 0) {
      result.push_back(backTracking);
      return;
    }

    for (size_t i = prevIndex; i < candidates.size(); i++) {
      const int& candidate = candidates[i];
      if (candidate > target) {
        continue;
      }
      backTracking.push_back(candidate);
      combineRecursive(candidates, result, backTracking, i, target - candidate);
      backTracking.pop_back();
    }
  }
};

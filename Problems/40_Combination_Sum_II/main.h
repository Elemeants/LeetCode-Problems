//
// 40. Combination Sum II
//
#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  vector2D combinationSum2(std::vector<int>& candidates, int target) {
    vector2D result;
    std::vector<int> row;

    std::sort(candidates.begin(), candidates.end());

    combinationRec(candidates, result, row, 0, target);

    return result;
  }

  void combinationRec(const std::vector<int>& candidates,
                      vector2D& results,
                      std::vector<int>& row,
                      const size_t prevIndex,
                      const int target) {
    if (target == 0) {
      results.push_back(row);
      return;
    }

    for (size_t i = prevIndex; i < candidates.size(); ++i) {
      if (candidates[i] > target || (i > prevIndex && candidates[i] == candidates[i - 1])) {
        continue;
      }
      row.push_back(candidates[i]);
      combinationRec(candidates, results, row, i + 1, target - candidates[i]);
      row.pop_back();
    }
  }
};
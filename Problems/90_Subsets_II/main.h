//
// 90. Subsets II
//
#pragma once

#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  vector2D subsetsWithDup(std::vector<int>& nums) {
    if (nums.size() == 0) {
      return {{}};
    }

    vector2D result = {{}};
    std::vector<int> path;

    std::sort(nums.begin(), nums.end());

    backtracking(result, path, nums, 0);

    return result;
  }

  void backtracking(
    vector2D& result,
    std::vector<int>& path,
    const std::vector<int>& nums,
    const size_t prevIndex
  ) {
    if (path.size() == nums.size()) {
      return;
    }

    for (size_t i = prevIndex; i < nums.size(); i++) {
      if (i != prevIndex && nums[i] == nums[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      result.push_back(path);
      backtracking(result, path, nums, i + 1);
      path.pop_back();
    }
  }
};

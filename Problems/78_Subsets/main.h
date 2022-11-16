//
// 78. Subsets
//
#pragma once

#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution
{
public:
  vector2D subsets(std::vector<int> &nums)
  {
    vector2D result = {{}};
    std::vector<int> subset;
    std::sort(nums.begin(), nums.end());

    recursive(nums, subset, 0, result);

    return result;
  }

  void recursive(
      const std::vector<int> &nums,
      std::vector<int> &subset,
      const size_t prevIndex,
      vector2D &result)
  {
    if (subset.size() == nums.size())
    {
      return;
    }

    for (size_t index = prevIndex; index < nums.size(); ++index)
    {
      const int n = nums[index];
      subset.push_back(n);
      result.push_back(subset);
      recursive(nums, subset, index + 1, result);
      subset.pop_back();
    }
  }
};

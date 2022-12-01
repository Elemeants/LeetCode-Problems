//
// 47. Permutations II
//
#pragma once

#include <map>
#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  vector2D permuteUnique(std::vector<int>& nums) {
    vector2D result;

    std::sort(nums.begin(), nums.end());
    std::vector<int> permutation;
    std::map<int, int> selected;

    for (const int& num : nums) {
      selected[num] ++;
    }

    permute(nums, result, permutation, selected);

    return result;
  }

  void permute(const std::vector<int>& nums, vector2D& result,
               std::vector<int>& permutation, std::map<int, int>& selected) {
    if (permutation.size() == nums.size()) {
      result.push_back(permutation);
      return;
    }

    for (const auto& item : selected) {
      if (selected[item.first] == 0) {
        continue;
      }
      selected[item.first]--;
      permutation.push_back(item.first);
      permute(nums, result, permutation, selected);
      permutation.pop_back();
      selected[item.first]++;
    }
  }
};

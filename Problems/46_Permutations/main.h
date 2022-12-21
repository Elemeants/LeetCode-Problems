//
// 46. Permutations
//
#pragma once

#include <deque>
#include <vector>
#include <unordered_map>

using listOfPermutations = std::vector<std::vector<int>>;

class Solution
{
public:
  listOfPermutations permute(std::vector<int> &nums)
  {
    listOfPermutations permutations;
    std::deque<int> deque;
    std::vector<int> perm;
    std::unordered_map<int, bool> visited;
    for (size_t i = 0; i < nums.size(); ++i) {
      visited[i] = false;
    }

    permute_recursive (permutations, nums, visited, perm);

    return permutations;
  }

  void permute_recursive (
      listOfPermutations&             result,
      const std::vector<int>&         base,
      std::unordered_map<int, bool>&  visited,
      std::vector<int>&               permutation)
  {
    const size_t base_size = base.size();
    if (permutation.size() == base_size) {
      result.push_back(permutation);
      return;
    }

    for (size_t index = 0; index < base_size; index++) {
      if (visited[index] == true) {
        continue;
      }

      visited[index] = true;
      permutation.push_back(base[index]);
      permute_recursive (result, base, visited, permutation);
      permutation.pop_back();
      visited[index] = false;
    }
  }
};

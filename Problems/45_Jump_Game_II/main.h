//
// 45. Jump Game II
//
#pragma once

#include <deque>
#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    std::deque<int> path;
    const int maxIndex = (int)nums.size() - 1;

    for (int index = (maxIndex - 1); index >= 0; index--) {
      insert(path, maxIndex, index, index + nums[index]);
    }

    return path.size();
  }

 private:
  void insert(std::deque<int>& path, int maxIndex, int index, int maxJumpIndex) {
    // Jump can't reach path
    if (
      (!path.empty() && path.back() > maxJumpIndex) ||
      (index == maxJumpIndex) ||
      (path.empty() && maxJumpIndex < maxIndex)
    ) {
      return;
    }

    // No need to search, we found a min node to jump to last index
    if (maxJumpIndex >= maxIndex) {
      path.clear();
      path.push_back(index);
      return;
    }

    const int n_e = (int)path.size() - 1;
    int last_index = n_e;
    for (int e = n_e; e >= 0; e--) {
      const int node = path[e];
      if (node <= maxJumpIndex) {
        last_index = e + 1;
        if (node == maxJumpIndex) {
          break;
        }
      }
    }

    path.erase(path.begin() + last_index, path.end());
    path.push_back(index);
  }
};
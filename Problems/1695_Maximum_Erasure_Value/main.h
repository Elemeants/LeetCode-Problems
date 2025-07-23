//
// 1695. Maximum Erasure Value
//
#pragma once

/*

Ok, so the think is to get the MAX subarray sum of unique elements.

So first of all, a brute force solution... wait

4 2 4 5 6 -> [2 4 5 6] ->= 17
5 2 1 2 5 2 1 2 5 -> [5 2 1] ->= 8

0 4 6 10 15 21
            _
  _


Possible subarrays of
4 2 4 2

[4]       = 4
[4 2]     = 6
[2 4]     = 6
[4]       = 4

So I can use a two pointer approach to keep the subarray of unique elements.
then use a global max tracker to check what was the max sum during the
permutations.

-- Solved

I think I can use a prefix sum array to just get the current window indexes to calculate the window sum.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <span>

class Solution {
 public:
  int maximumUniqueSubarray(std::vector<int>& nums) {
    std::pair<int, int> window_idx = std::make_pair(0, 0);
    std::unordered_map<int, int> unique_numbers;
    int* prefix_sum = (int*)std::malloc(sizeof(int) * (nums.size() + 1));
    int global_max = 0;

    while (window_idx.second < nums.size()) {
      const int number = nums[window_idx.second];
      const int idx = window_idx.second + 1;
      const std::unordered_map<int, int>::iterator& it =
          unique_numbers.find(number);
      if (it != unique_numbers.end()) {
        window_idx.first = std::max(it->second + 1, window_idx.first);
      }
      unique_numbers[number] = window_idx.second;

      const int prefix = number + prefix_sum[window_idx.second];
      const int window_sum = prefix - prefix_sum[window_idx.first];
      global_max = std::max(global_max, window_sum);

      prefix_sum[idx] = prefix;
      window_idx.second++;
    }

    std::free(prefix_sum);

    return global_max;
  }
};

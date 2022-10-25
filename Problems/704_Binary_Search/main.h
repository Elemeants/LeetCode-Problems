//
// 704. Binary Search
//
#pragma once

#include <vector>
#include <algorithm>
#include <stdint.h>

class Solution {
public:
    int search (std::vector<int>& nums, int target) {
        // Constrains of the problem means that the nums vector is already sorted in ascending order.
        return recursiveSearch (nums, 0, nums.size() - 1, target);
    }

private:
    int recursiveSearch (const std::vector<int>& nums, size_t startIndex, size_t endIndex, int target) {
        const int split_index = ((endIndex - startIndex) / 2) + startIndex;
        if (split_index < 0 || split_index >= nums.size()) {
            return -1;
        }

        const int index_value = nums[split_index];
        if (index_value == target) {
            return split_index;
        } else if (endIndex == startIndex) {
            return -1;
        } else if (index_value > target) {
            return recursiveSearch (nums, startIndex, split_index - 1, target);
        } else if (index_value < target) {
            return recursiveSearch (nums, split_index + 1, endIndex, target);
        }

        return -1;
    }
};

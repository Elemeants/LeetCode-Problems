//
// 35. Search Insert Position
//
#pragma once

#include <vector>
#include <array>
#include <stdint.h>

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            const int mid = ((right - left) / 2) + left;
            const int min_val = nums[mid];
            if (min_val == target) {
                return mid;
            }

            if (target < min_val) {
                right = mid - 1;
            } else if (target > min_val) {
                left = mid + 1;
            }
        }

        return right + 1;
    }
};

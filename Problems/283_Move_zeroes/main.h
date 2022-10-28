//
// 283. Move Zeroes
//
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto insertingIt = nums.begin();
        auto lookingIt = nums.begin();
        while (lookingIt < nums.end()) {
            if (*lookingIt != 0) {
                *insertingIt++ = std::move(*lookingIt);
            }
            lookingIt++;
        }
        while (insertingIt < nums.end()) {
            *insertingIt++ = 0;
        }
    }
};

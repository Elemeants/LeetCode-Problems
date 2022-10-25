//
// 219. Contains Duplicate II
//
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        const int nums_size = nums.size();
        std::unordered_map<int, int> lastIndexForEachNum;
        int i = 0;
        for (int num : nums) {
            auto e = lastIndexForEachNum.find(num);
            if (e == lastIndexForEachNum.end()) {
                lastIndexForEachNum[num] = i;
            }
            else if (abs(i - e->second) <= k) {
                return true;
            }
            else {
                e->second = i;
            }
            i++;
        }
        return false;
    }
};

//
// 189. Rotate Array
//
#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <iterator>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        const int nums_size = nums.size();
        const int _k = k % nums_size;
        // O(n * (n - k)) = 
        const int no_iters = ((nums_size - 1) * (nums_size - _k));
        for (int i = 0; i < no_iters; i++) {
            const int a = i % nums_size;
            const int b = (i + nums_size - 1) % nums_size;
            const int va = nums[a];
            const int vb = nums[b];
            nums[b] = va;
            nums[a] = vb;
        }
    }
};

class STDSolution {
public:
    void rotate(std::vector<int>& nums, int k) {
        const int nums_size = nums.size();
        const int _k = k % nums_size;
        std::rotate(nums.rbegin(), nums.rbegin() + _k, nums.rend());
    }
};
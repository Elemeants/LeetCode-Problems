//
// 977. Squares of a Sorted Array
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
    virtual std::vector<int> sortedSquares(const std::vector<int> nums) const = 0;
};

class IteratorSolution : public Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int> nums) const override {
        std::vector<int> output;
        output.resize(nums.size());
        int left_index = 0;
        int right_index = nums.size() - 1;
        int output_i = right_index;

        while (left_index <= right_index && output_i >= 0) {
            const int& l_v = abs(nums[left_index]);
            const int& r_v = nums[right_index];
            if (l_v <= r_v) {
                output[output_i] = r_v * r_v;
                right_index --;
            } else if (l_v > r_v) {
                output[output_i] = l_v * l_v;
                left_index ++;
            }
            output_i--;
        }

        return output;
    }
};

class MapSolution : public Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int> nums) const override {
        std::map<int, int> table;
        std::vector<int> output;
        size_t output_i = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            const int& v = nums[i];
            auto r = table.try_emplace(v * v, 0);
            r.first->second++;
        }

        for (const auto& p : table) {
            for (size_t i = 0; i < p.second; i++) {
                output.push_back(p.first);
            }
        }

        return output;
    }
};
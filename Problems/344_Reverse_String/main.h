//
// 344. Reverse String
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
    void reverseString(std::vector<char>& s) {
        const auto middle = s.begin() + (s.size() / 2);
        auto it = s.begin();
        auto rIt = s.rbegin();
        while (it < middle) {
            char aux = *it;
            *it++ = *rIt;
            *rIt++ = aux;
        }
    }
};

//
// 1662. Check If Two String Arrays are Equivalent
//
#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <thread>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string w1;
        std::string w2;
        for (const std::string w : word1) {
            w1.append(w);
        }
        for (const std::string w : word2) {
            w2.append(w);
        }

        return w1 == w2;
    }
};

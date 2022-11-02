//
// 567. Permutation String
//
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>
#include <unordered_map>
#include <deque>

class Solution
{
public:
    bool checkInclusion(const std::string s1, const std::string s2)
    {
        const size_t size_s1 = s1.size();
        const size_t size_s2 = s2.size();

        if (size_s1 > size_s2)
        {
            return false;
        }
        else if (size_s1 == size_s2)
        {
            return std::is_permutation(s1.begin(), s1.end(), s2.begin());
        }

        std::unordered_map<char, std::pair<int, int>> perm;

        for (const auto& c : s1) {
            perm.try_emplace(c, std::make_pair(0, 0));
            perm[c].second ++;
        }

        for (size_t i = 0; i < size_s2; ++i)
        {
            const char& c = s2[i];
            if (perm.count(c) > 0) {
                perm[c].first ++;
            }

            if (i >= size_s1) {
                const char& c_p = s2[i - size_s1];
                if (perm.count(c_p) > 0) {
                    perm[c_p].first --;
                }
            }

            const bool finished = std::all_of(perm.begin(), perm.end(), [](const std::pair<char, std::pair<int, int>>& e) -> bool {
                return e.second.first == e.second.second;
            });
            if (finished) {
                return true;
            }
        }

        return false;
    }
};
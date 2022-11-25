//
// 3. Longest Substring Without Repeating Characters
//
#pragma once

#include <set>
#include <stdint.h>
#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        size_t max_size = 0;
        std::set<char> uniques;
        int tail = 0;

        for (int head = 0; head < s.size(); head++) {
            const char c = s[head];
            if (uniques.find(c) != uniques.end()) {
                while (tail < head && s[tail] != c) {
                    tail ++;
                }
                tail ++;
            } else {
                uniques.insert(c);
                const int size = (head - tail) + 1;
                if (size > max_size) {
                    max_size = size;
                }
            }
        }

        return max_size;
    }
};
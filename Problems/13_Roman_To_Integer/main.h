//
// 13. Roman to Integer
//
#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <map>

class Solution {
    std::map<char, int> MapRomanCharToIntegerValue = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };
public:
    int romanToInt(std::string s) {
        const int size = s.size();
        const char *p = s.c_str();

        int result = 0;
        int prevValue = 0;
        for (int i = 0; i < size; i++) {
            const char c = p[i];
            const int currentValue = MapRomanCharToIntegerValue[c];
            result += currentValue;
            if (prevValue < currentValue) {
                result -= prevValue * 2;
            }
            prevValue = currentValue;
        }
        return result;
    }
};

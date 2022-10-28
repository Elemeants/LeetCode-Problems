//
// 557. Reverse Words III
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
    std::string reverseWords(std::string s) {
        int left = 0;
        int right = 0;
        std::string output = s;
        char* s_str = (char*)output.c_str();
        const int s_lenght = s.length();

        for (int i = 0; i < s_lenght; i++) {
            const char c = s_str[i];
            if (c == ' ' || i == (s_lenght - 1)) { 
                right = i == (s_lenght - 1) ? i : i - 1;
                const int middle = ((right - left) / 2) + left;
                while (left <= middle) {
                    const char aux = s_str[left];
                    s_str[left++] = s_str[right];
                    s_str[right--] = aux;
                }
                
                left = i + 1;
            }
        }

        return output;
    }
};

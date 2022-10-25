//
// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
//
#pragma once

#include <string>

class Solution {
public:
    int minPartitions(std::string n) {
        int max_number = 0;
        for (char c : n) {
            char c_digit = c - '0';
            if (c_digit > max_number) {
                max_number = c_digit;
                if (max_number == 9) {
                    break;
                }
            }
        }
        return max_number;
    }
};

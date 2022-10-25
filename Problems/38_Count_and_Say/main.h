//
// 38. Count and Say
//
#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <iosfwd>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else if (n == 2)
        {
            return "11";
        }
        return CalculateCountAndSayByNumber(countAndSay(n - 1));
    }

    std::string CalculateCountAndSayByNumber(std::string n)
    {
        std::string str;
        char previous_c = n[0];
        int counted_chars = 0;

        for (char c : n)
        {
            if (c == previous_c)
            {
                counted_chars++;
            }
            else
            {
                str += std::to_string(counted_chars);
                str += previous_c;
                counted_chars = 1;
            }
            previous_c = c;
        }

        if (counted_chars > 0)
        {
            str += std::to_string(counted_chars);
            str += previous_c;
        }

        return str;
    }
};

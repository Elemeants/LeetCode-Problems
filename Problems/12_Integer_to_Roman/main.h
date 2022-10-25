//
// 12. Integer to Roman
//
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>

class Solution
{
    const std::array<std::pair<int, char>, 7> map = {
        std::make_pair(1000, 'M'),
        std::make_pair(500, 'D'),
        std::make_pair(100, 'C'),
        std::make_pair(50, 'L'),
        std::make_pair(10, 'X'),
        std::make_pair(5, 'V'),
        std::make_pair(1, 'I')};

    const int GetSubstractionIndex(int n)
    {
        if (n > 100)
        {
            return 2;
        }
        else if (n > 10)
        {
            return 4;
        }
        else
        {
            return 6;
        }
    }

public:
    std::string intToRoman(int num)
    {
        std::string str;
        str.reserve(20);
        int local_num = num;

        for (int index = 0; index < map.size() && local_num > 0; index++)
        {
            const std::pair<int, char> &romanValues = map[index];
            const std::pair<int, char> &subRomanValues = map[GetSubstractionIndex(romanValues.first)];

            int d = local_num / romanValues.first;
            local_num %= romanValues.first;

            bool substractCase = (local_num - (romanValues.first - subRomanValues.first)) >= 0 && index < (map.size() - 1);

            if (substractCase)
            {
                d++;
            }

            for (int a = 0; a < d; a++)
            {
                if (a == (d - 1) && substractCase)
                {
                    local_num -= (romanValues.first - subRomanValues.first);
                    str += subRomanValues.second;
                }
                str += romanValues.second;
            }
        }
        return str;
    }
};

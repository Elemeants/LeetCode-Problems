//
// 3. Longest Substring Without Repeating Characters
//
#pragma once

#include <algorithm>
#include <stdint.h>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        size_t max_size = 0;
        size_t size = 0;
        const char *left_edge = s.c_str();
        const char *right_edge = s.c_str();

        for (char c : s)
        {
            size = right_edge - left_edge;

            if (size > 0 && std::find(left_edge, right_edge, c) != right_edge)
            {
                if (max_size < size)
                {
                    max_size = size;
                }

                while (left_edge <= right_edge)
                {

                    if (c == *left_edge)
                    {
                        left_edge++;
                        break;
                    }

                    left_edge++;
                }
            }

            right_edge++;
        }

        if (max_size < right_edge - left_edge)
        {
            max_size = right_edge - left_edge;
        }

        return max_size;
    }
};
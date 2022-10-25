//
// 6. Zigzag Conversion
//
#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        size_t row = 0;
        size_t index = 0;
        size_t ch_in_row_index = 0;
        size_t string_size = s.size();
        std::string out_str;

        if (numRows == 1)
        {
            return s;
        }

        for (row = 0; row < numRows; row++)
        {
            index = row;
            ch_in_row_index = 0;
            while (index < string_size)
            {
                out_str.push_back(s[index]);
                index = getNextIndexFromRow(index, row, ch_in_row_index, numRows);
                ch_in_row_index++;
            }
        }

        return out_str;
    }

    size_t getNextIndexFromRow(size_t currIndex, size_t row, size_t chs_in_row_index, size_t maxRows)
    {
        size_t nextIndex = currIndex;
        if (row == 0 || row == (maxRows - 1))
        {
            return currIndex + (2 * maxRows) - 2;
        }
        else if (chs_in_row_index % 2 == 0)
        {
            nextIndex += ((maxRows - 1) - row);
            return nextIndex + ((maxRows - 1) - row);
        }
        else
        {
            nextIndex += row;
            return nextIndex + row;
        }
    }
};
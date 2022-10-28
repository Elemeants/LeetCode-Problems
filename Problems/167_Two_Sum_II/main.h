//
// 167. Two Sum II
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
    using NumberValue = int;
    using NumberIndex = int;

public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        const int array_size = numbers.size();
        //
        // Base case
        //
        if ((array_size == 2) && ((numbers[0] + numbers[1]) == target))
        {
            return std::vector<int>{1, 2};
        }

        std::vector<int> result;
        result.resize(2);

        // Find first occurrence of two sum, since there is only one possible occurrence
        // std::unordered_map<NumberValue, NumberIndex> map;
        int positiveNumberIndex = -1;
        for (int i = 0; i < array_size; ++i)
        {
            if (numbers[i] > 0)
            {
                positiveNumberIndex = i;
                break;
            }
        }

        int a = 0;
        while (a < (array_size - 1))
        {
            const int a_v = numbers[a];
            const int missingNumber = target - a_v;
            int startIndex = a + 1;
            int endIndex = positiveNumberIndex;

            if (missingNumber > 0)
            {
                // Start searching from positiveNumberIndex
                startIndex = positiveNumberIndex;
                endIndex = array_size;
            }

            for (int j = startIndex; j < endIndex; ++j)
            {
                if (missingNumber == numbers[j])
                {
                    return {a + 1, j + 1};
                }
            }
            a++;
        }

        return result;
    }
};

class MapSolution
{
    using NumberValue = int;
    using NumberIndex = int;

public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        const int array_size = numbers.size();
        //
        // Base case
        //
        if ((array_size == 2) && ((numbers[0] + numbers[1]) == target))
        {
            return std::vector<int>{1, 2};
        }

        std::vector<int> result;
        result.resize(2);

        // Find first occurrence of two sum, since there is only one possible occurrence
        std::unordered_map<NumberValue, NumberIndex> map;
        int positiveNumberIndex = -1;
        int prevValue = 0;
        for (int i = 0; i < array_size; ++i)
        {
            const int v = numbers[i];
            map[v] = i;
            prevValue = v;
        }

        int a = 0;
        while (a < (array_size - 1))
        {
            const int a_v = numbers[a];
            const int missingNumber = target - a_v;

            if (map.count(missingNumber) > 0) {
                return {a + 1, map[missingNumber] + 1};
            }

            a++;
        }

        return result;
    }
};

//
// 13. 3Sum
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

class Index3D
{
public:
    int x;
    int y;
    int z;

    Index3D() : x(0), y(0), z{0} {};
    Index3D(const int x, const int y, const int z) : x(x), y(y), z(z){};

    Index3D &operator=(const Index3D &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    };

    bool operator==(const Index3D &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    };
};

namespace std
{
    template <>
    struct hash<Index3D>
    {
        std::size_t operator()(const Index3D &index) const noexcept
        {
            return index.x + (index.y * 10) + (index.z * 100);
        }
    };
};

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> nums)
    {
        std::vector<std::vector<int>> v;
        std::unordered_set<Index3D> table;

        if (nums.size() == 3)
        {
            if (isTripletValid(Index3D{nums[0], nums[1], nums[2]}))
            {
                v.push_back(nums);
            }
            return v;
        }

        std::sort(nums.begin(), nums.end());

        if (nums[0] > 0)
        {
            return v;
        }

        std::unordered_map<int, int> numIndexes;
        int indexWherePositiveNumsStarts = 0;
        int countZeros = 0;

        for (int x = 0; x < nums.size(); x++)
        {
            numIndexes[nums[x]] = x;

            if (nums[x] == 0) {
                countZeros ++;
            }

            if (nums[x] > 0 && indexWherePositiveNumsStarts == 0) {
                indexWherePositiveNumsStarts = x;
            }
        }

        if (indexWherePositiveNumsStarts == 0 && countZeros >= 3) {
            v.push_back({0, 0, 0});
        }

        for (int x = 0; x < indexWherePositiveNumsStarts; x++)
        {
            const int num_x = nums[x];
            if (nums[x] > 0)
            {
                break;
            }

            for (int z = x + 1; z < (nums.size() - 1); z++)
            {
                const int num_z = nums[z];

                int neededNumber = -(num_x + num_z);
                auto neededNumberIndex = numIndexes.find(neededNumber);
                if (neededNumberIndex == numIndexes.end() || neededNumberIndex->second <= z)
                {
                    continue;
                }

                Index3D i(num_x, num_z, neededNumberIndex->first);
                if (isTripletValid(i) && table.find(i) == table.end())
                {
                    v.push_back({i.x, i.y, i.z});
                    table.insert(i);
                }
            }
        }

        return v;
    }

    bool isTripletValid(Index3D index)
    {
        return (index.x + index.y + index.z) == 0;
    }
};

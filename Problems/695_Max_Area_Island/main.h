//
// 692. Top K Frequent Words
//
#pragma once

#include <vector>

using vector2D = std::vector<std::vector<int>>;

class Solution {
public:
    int maxAreaOfIsland(vector2D& grid) {
        const int size_x = grid.size();
        const int size_y = grid[0].size();
        int maxArea = 0;
        for (int x = 0; x < size_x; x++) {
            for (int y = 0; y < size_y; y++) {
                if (grid[x][y] == 1) {
                    const int localArea = getIslandSizeAndMarkAsCounted (grid, x, y);
                    if (maxArea < localArea) { maxArea = localArea; }
                }
            }
        }
        return maxArea;
    }

    int getIslandSizeAndMarkAsCounted (vector2D &image, const int sr, const int sc)
    {
        int countNodes = 0;

        iterateNodesUpdateValueAndCount (countNodes, image, sr, sc, 1, 2);

        return countNodes;
    }

    void iterateNodesUpdateValueAndCount (int& countNodes, vector2D &image, const int x, const int y, const int &original, const int &newValue)
    {
        if ((x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) || (image[x][y] != original)) {
            return;
        }

        image[x][y] = newValue;
        countNodes ++;
        iterateNodesUpdateValueAndCount(countNodes, image, x, y - 1, original, newValue);
        iterateNodesUpdateValueAndCount(countNodes, image, x, y + 1, original, newValue);
        iterateNodesUpdateValueAndCount(countNodes, image, x - 1, y, original, newValue);
        iterateNodesUpdateValueAndCount(countNodes, image, x + 1, y, original, newValue);
    }
};

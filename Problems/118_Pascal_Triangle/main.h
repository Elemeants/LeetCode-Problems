//
// 118. Pascal's Triangle
//
#pragma once

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> output;
        recursive (output, numRows);
        return output;
    }

    void recursive (std::vector<std::vector<int>>& triangle, const int n_row) {
        std::vector<int> row;
        row.resize(n_row);
        if (n_row == 0) {
            return;
        } else if (n_row == 1) {
            row[0] = 1;
            triangle.push_back(row);
        } else {
            recursive (triangle, n_row - 1);
            std::vector<int> row;
            row.resize(n_row);
            row[0] = 1;
            row[row.size() - 1] = 1;
            for (size_t i = 1; i < (row.size() - 1); i++) {
                row[i] = triangle[n_row - 2][i] + triangle[n_row - 2][i - 1];
            }
            triangle.push_back(row);
        }
    }
};


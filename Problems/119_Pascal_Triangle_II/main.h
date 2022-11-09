//
// 119. Pascal's Triangle II
//
#pragma once

#include <vector>
#include <stdlib.h>

class Solution {
  public:
    std::vector<int> getRow(int rowIndex) {
      std::vector<int> row;
      row.resize(rowIndex);

      recursive(row, rowIndex + 1);

      return row;
    }


    void recursive (std::vector<int>& prev_row, const int n_row) {
      std::vector<int> row;
      row.resize(n_row);
      if (n_row == 0) {
        return;
      } else if (n_row == 1) {
        row[0] = 1;
        prev_row = row;
      } else {
        recursive (prev_row, n_row - 1);
        std::vector<int> row;
        row.resize(n_row);
        row[0] = 1;
        row[row.size() - 1] = 1;
        for (size_t i = 1; i < (row.size() - 1); i++) {
          row[i] = prev_row[i] + prev_row[i - 1];
        }
        prev_row = row;
      }
    }
};


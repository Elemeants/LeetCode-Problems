//
// 547. Number of Provinces
//
#pragma once

#include <vector>
#include <deque>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  int findCircleNum(vector2D& isConnected) {
    std::deque<int> nodes;
    int provinces = 0;

    for (size_t city = 0; city < isConnected.size(); city++) {
      if (isConnected[city][city] != 1) {
        continue;
      }

      nodes.push_back(city);
      while (nodes.size() > 0) {
        const auto& i = nodes.back(); nodes.pop_back();
        isConnected[i][i] = 2;

        for (size_t x = 0; x < isConnected.size(); x++) {
          if (isConnected[x][i] == 1) {
            isConnected[x][i] = 2;
            nodes.push_front(x);
          }
        }
      }
      // printGrid(isConnected);
      provinces ++;
    }

    return provinces;
  }

  void printGrid(vector2D& grid) {
    const int x_high = grid.size();
    const int y_high = grid[0].size();

    for (int x = 0; x < x_high; ++x) {
      for (int y = 0; y < y_high; ++y) {
        std::cout << " " << grid[x][y];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
};

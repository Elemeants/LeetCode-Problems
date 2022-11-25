//
// 200. Number of Islands
//
#pragma once

#include <deque>
#include <vector>

using vector2D = std::vector<std::vector<char>>;

class Solution {
 public:
  int numIslands(vector2D& grid) {
    const int x_high = grid.size();
    const int y_high = grid[0].size();
    int count_of_islands = 0;

    for (int x = 0; x < x_high; ++x) {
      for (int y = 0; y < y_high; ++y) {
        if (grid[x][y] == '1') {
          fillIsland(grid, x, y);
          count_of_islands ++;
        }
      }
    }

    return count_of_islands;
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

  void fillIsland(vector2D& grid, int x, int y) {
    const int x_lower = 0;
    const int y_lower = 0;
    const int x_high = grid.size() - 1;
    const int y_high = grid[0].size() - 1;

    std::deque<std::pair<int, int>> nodes;
    nodes.push_back(std::make_pair(x, y));

    while (nodes.size() > 0) {
      const auto i = nodes.back(); nodes.pop_back();
      grid[i.first][i.second] = 'x';

      if (i.first + 1 <= x_high && grid[i.first + 1][i.second] == '1') {
        nodes.push_back(std::make_pair(i.first + 1, i.second));
      }
      if (i.first - 1 >= x_lower && grid[i.first - 1][i.second] == '1') {
        nodes.push_back(std::make_pair(i.first - 1, i.second));
      }
      if (i.second + 1 <= y_high && grid[i.first][i.second + 1] == '1') {
        nodes.push_back(std::make_pair(i.first, i.second + 1));
      }
      if (i.second - 1 >= y_lower && grid[i.first][i.second - 1] == '1') {
        nodes.push_back(std::make_pair(i.first, i.second - 1));
      }
    }
  }
};

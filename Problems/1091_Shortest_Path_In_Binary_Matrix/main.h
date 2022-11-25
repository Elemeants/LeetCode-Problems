//
// 1091. Shortest Path in Binary Matrix
//
#pragma once

#include <vector>
#include <deque>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector2D& grid) {
    if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) {
      return -1;
    }

    std::deque<std::pair<std::pair<int, int>, int>> nodes;
    nodes.push_back(std::make_pair(std::make_pair(0, 0), 0));
    const int x_lower = 0;
    const int y_lower = 0;
    const int x_high = grid.size() - 1;
    const int y_high = grid[0].size() - 1;

    while (nodes.size() > 0) {
      auto node = nodes.back(); nodes.pop_back();

      if (grid[node.first.first][node.first.second] != 0) {
        continue;
      }

      grid[node.first.first][node.first.second] = node.second + 1;

      if (node.first.first == x_high && node.first.second == y_high) {
        return node.second + 1;
      }

      // Down
      if (node.first.first + 1 <= x_high && grid[node.first.first + 1][node.first.second] == 0) {
        auto coord = std::make_pair(node.first.first + 1, node.first.second);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Right-Down
      if (node.first.first + 1 <= x_high && node.first.second + 1 <= y_high && grid[node.first.first + 1][node.first.second + 1] == 0) {
        auto coord = std::make_pair(node.first.first + 1, node.first.second + 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Left-Down
      if (node.first.first + 1 <= x_high && node.first.second - 1 >= y_lower && grid[node.first.first + 1][node.first.second - 1] == 0) {
        auto coord = std::make_pair(node.first.first + 1, node.first.second - 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Up
      if (node.first.first - 1 >= x_lower && grid[node.first.first - 1][node.first.second] == 0) {
        auto coord = std::make_pair(node.first.first - 1, node.first.second);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Right-Up
      if (node.first.first - 1 >= x_lower && node.first.second + 1 <= y_high && grid[node.first.first - 1][node.first.second + 1] == 0) {
        auto coord = std::make_pair(node.first.first - 1, node.first.second + 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Left-Up
      if (node.first.first - 1 >= x_lower && node.first.second - 1 >= y_lower && grid[node.first.first - 1][node.first.second - 1] == 0) {
        auto coord = std::make_pair(node.first.first - 1, node.first.second - 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Right
      if (node.first.second + 1 <= y_high && grid[node.first.first][node.first.second + 1] == 0) {
        auto coord = std::make_pair(node.first.first, node.first.second + 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
      // Left
      if (node.first.second - 1 >= y_lower && grid[node.first.first][node.first.second - 1] == 0) {
        auto coord = std::make_pair(node.first.first, node.first.second - 1);
        nodes.push_front(std::make_pair(coord, node.second + 1));
      }
    }

    return -1;
  }
};

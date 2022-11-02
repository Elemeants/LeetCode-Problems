//
// 994. Rotting Oranges
//
#pragma once

#include <vector>
#include <deque>
#include <unordered_set>

using matrix2D = std::vector<std::vector<int>>;

class Solution
{
public:
  int orangesRotting(matrix2D &grid)
  {
    const int size_x = grid.size();
    const int size_y = grid[0].size();

    const std::vector<std::pair<int, int>> relativeCoords = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::deque<std::pair<std::pair<int, int>, int>> distances;

    for (int x = 0; x < size_x; x++)
    {
      for (int y = 0; y < size_y; y++)
      {
        if (grid[x][y] == 2) {
          distances.push_back(std::make_pair(std::make_pair(x, y), 0));
        }
      }
    }

    int max_time = 0;
    while (distances.size() > 0) {
      const auto item = distances.front(); distances.pop_front();
      if (item.second > max_time) {
        max_time = item.second;
      }

      for (const std::pair<int, int> &looking : relativeCoords)
      {
        const int new_x = item.first.first + looking.first;
        const int new_y = item.first.second + looking.second;
        if ((new_x < 0 || new_y < 0 || new_x >= size_x || new_y >= size_y) || (grid[new_x][new_y] != 1))
        {
          continue;
        }

        grid[new_x][new_y] = 2;
        distances.push_back(std::make_pair(std::make_pair(new_x, new_y), item.second + 1));
      }
    }

    for (int x = 0; x < size_x; x++)
    {
      for (int y = 0; y < size_y; y++)
      {
        if (grid[x][y] == 1) {
          return -1;
        }
      }
    }

    return max_time;
  }
};

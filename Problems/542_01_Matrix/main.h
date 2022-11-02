//
// 542. 01 Matrix
//
#pragma once

#include <vector>
#include <deque>
#include <unordered_set>

using matrix2D = std::vector<std::vector<int>>;

class Solution
{
public:
  matrix2D updateMatrix(const matrix2D &mat)
  {
    matrix2D output = mat;
    const int size_x = output.size();
    const int size_y = output[0].size();

    const std::vector<std::pair<int, int>> relativeCoords = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::deque<std::pair<int, int>> distances;

    for (int x = 0; x < size_x; x++)
    {
      for (int y = 0; y < size_y; y++)
      {
        if (output[x][y] == 0) {
          distances.push_back(std::make_pair(x, y));
        } else {
          output[x][y] = -1;
        }
      }
    }

    while (distances.size() > 0)
    {
      const auto i = distances.front(); distances.pop_front();

      for (const std::pair<int, int> &looking : relativeCoords)
      {
        const int new_x = i.first + looking.first;
        const int new_y = i.second + looking.second;
        if ((new_x < 0 || new_y < 0 || new_x >= size_x || new_y >= size_y) || output[new_x][new_y] != -1)
        {
          continue;
        }

        output[new_x][new_y] = (output[i.first][i.second] + 1);
        distances.push_back(std::make_pair(new_x, new_y));
      }
    }

    return output;
  }
};

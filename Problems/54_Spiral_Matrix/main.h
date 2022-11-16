//
// 54. Spiral Matrix
//
#pragma once

#include <vector>
#include <iostream>

using vector2D = std::vector<std::vector<int>>;

class Solution
{
  typedef enum
  {
    Left,
    Down,
    Right,
    Up
  } DIRECTION;

public:
  std::vector<int> spiralOrder(const vector2D &matrix)
  {
    std::vector<int> order;
    int x = 0;
    int y = 0;
    int min_x = 0;
    int min_y = 0;
    int max_x = matrix[0].size();
    int max_y = matrix.size();

    DIRECTION dir = Left;
    order.resize(max_x * max_y);
    auto it = order.begin();

    while (it != order.end())
    {
      *it = matrix[y][x];
      it++;

      // Update X, Y position
      switch (dir)
      {
      case Left:
        if (x == (max_x - 1))
        {
          dir = Down;
          min_y++;
          y++;
        }
        else
        {
          x++;
        }
        break;
      case Down:
        if (y == (max_y - 1))
        {
          dir = Right;
          max_x--;
          x--;
        }
        else
        {
          y++;
        }
        break;
      case Right:
        if (x == min_x)
        {
          dir = Up;
          max_y--;
          y--;
        }
        else
        {
          x--;
        }
        break;
      case Up:
        if (y == min_y)
        {
          dir = Left;
          min_x++;
          x++;
        }
        else
        {
          y--;
        }
        break;
      }
    }

    return order;
  }
};

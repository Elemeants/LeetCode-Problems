//
// 11. Container With Most Water
//
#pragma once

#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int> &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int max_capacity = 0;
    while (left < right) {
      int capacity = (right - left) * std::min(height[left], height[right]);
      max_capacity = std::max(max_capacity, capacity);

      if (height[left] > height[right]) {
        right --;
      } else {
        left ++;
      }
    }
    return max_capacity;
  }
};
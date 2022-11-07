//
// 973. K Closest Points to Origin
//
#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

using point2D = std::vector<int>;
using vector2D = std::vector<std::vector<int>>;

float getDistanceToOrigin (const point2D& p) {
  return sqrt(pow(p[0], 2) + pow(p[1], 2));
}

class Solution
{
public:
  vector2D kClosest(vector2D &points, int k)
  {
    if (k == 0) {                     // No points
      return vector2D();
    } else if ((int)points.size() == k) {  // Don't need to filter.
      return points;
    }
    vector2D result(k);

    // Sort by distance from shortest to longest
    std::sort(points.begin(), points.end(), [](const point2D& pointA, const point2D& pointB) -> bool {
      return getDistanceToOrigin(pointA) < getDistanceToOrigin(pointB);
    });

    // Remove extra elements
    std::copy_n(points.begin(), k, result.begin());
    return result;
  }
};

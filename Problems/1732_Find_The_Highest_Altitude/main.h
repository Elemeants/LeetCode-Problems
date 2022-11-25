//
// 1732. Find the Highest Altitude
//
#pragma once

#include <vector>
#include <numeric>

class Solution
{
public:
  int largestAltitude(std::vector<int> &gain)
  {
    int max_altitude = 0;
    int altitude = 0;
    for (int &i : gain) {
      altitude += i;
      max_altitude = std::max(altitude, max_altitude);
    }
    return max_altitude;
  }
};

//
// 986. Interval List Intersections
//
#pragma once

#include <vector>
#include <iostream>

using vector2D = std::vector<std::vector<int>>;

class Solution
{
public:
  vector2D intervalIntersection(vector2D &firstList, vector2D &secondList)
  {
    vector2D result;
    auto secndIt = secondList.begin();

    while (secndIt != secondList.end()) {
      for (const std::vector<int> &interval: firstList) {
        const std::vector<int> join = getIntervalFromInnerJoin(*secndIt, interval);
        if (join.size() > 0) {
          result.push_back(join);
        }
      }
      secndIt ++;
    }

    return result;
  }

  std::vector<int> getIntervalFromInnerJoin(const std::vector<int> &intervalA, const std::vector<int> &intervalB) {
    const int start_A = intervalA[0];
    const int end_A = intervalA[1];
    const int start_B = intervalB[0];
    const int end_B = intervalB[1];
    const bool start_A_isOnInvervalB = edgeIsOnInterval(start_A, intervalB);
    const bool end_A_isOnInvervalB   = edgeIsOnInterval(end_A, intervalB);
    const bool start_B_isOnInvervalA = edgeIsOnInterval(start_B, intervalA);
    const bool end_B_isOnInvervalA   = edgeIsOnInterval(end_B, intervalA);

    if (start_A_isOnInvervalB && !end_A_isOnInvervalB) {
      return {start_A, end_B};
    } else if (!start_A_isOnInvervalB && end_A_isOnInvervalB) {
      return {start_B, end_A};
    } else if (start_A_isOnInvervalB && end_A_isOnInvervalB) {
      return {start_A, end_A};
    } else if (start_B_isOnInvervalA && end_B_isOnInvervalA) {
      return {start_B, end_B};
    }
    return {};
  }

  bool edgeIsOnInterval (int edge, const std::vector<int>& interval) {
    const int start = interval[0];
    const int end = interval[1];
    return ((edge >= start) && (edge <= end));
  }
};
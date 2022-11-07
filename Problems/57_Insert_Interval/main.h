//
// 57. Insert Interval
//
#pragma once

#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

using vector2D = std::vector<std::vector<int>>;

class Solution {
public:
    vector2D insert(const vector2D& intervals, const std::vector<int>& newInterval) {
        vector2D output;
        std::vector<int> intervalToInsert = newInterval;
        if (intervals.size() == 0) {
          output.push_back(intervalToInsert);
          return output;
        }

        bool wasInserted = false;

        for (const auto& item : intervals) {
          if (!wasInserted && areIntervalsOverlaping(item, intervalToInsert)) {
            // Update limits.
            intervalToInsert[0] = std::min(item[0], intervalToInsert[0]);
            intervalToInsert[1] = std::max(item[1], intervalToInsert[1]);
          } else {
            if (!wasInserted && (item[0] > intervalToInsert[1])) {
              output.push_back(intervalToInsert);
              wasInserted = true;
            }
            output.push_back(item);
          }
        }

        // No overlapping, add to the end
        if (wasInserted == false) {
          output.push_back(intervalToInsert);
        }
       
        return output;
    }

    bool areIntervalsOverlaping(const std::vector<int>& intervalA, const std::vector<int>& intervalB) {
      const int start_A = intervalA[0];
      const int end_A = intervalA[1];
      const int start_B = intervalB[0];
      const int end_B = intervalB[1];
      if ((start_A >= start_B)  && (start_A <= end_B)) { return true; }
      if ((end_A >= start_B)    && (end_A <= end_B))   { return true; }
      if ((start_B >= start_A)  && (start_B <= end_A)) { return true; }
      if ((end_B >= start_A)    && (end_B <= end_A))   { return true; }
      return false;
    }
};

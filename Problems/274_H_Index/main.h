//
// 274. H-Index
//
#pragma once

// 3 0 6 1 5
// 0 -> 0
// 1 -> 4
// 2 -> 3
// 3 -> 3
// 4 -> 2
// 5 -> 2
// 6 -> 1
//               _
// h-index:    5 6 7 8 9
// citations:  5 5 5 5 6 6 6 6 7 7
//                     _
// remaining: 10 9 8 7 6 5 4 3 2 1

// So let's
// 1. Order the citations from lower -> greater
// 2. Find h-index by:
//    Starting h-index at the lowest value to the array length
//    If the length is lower than the lowest value then 0.
//    Else:
//      - Loop over the citations until ((citations_length - citations_index) > h-index)
//        because you can't find a h-index greater since there are no enough elements.
//      - If citations[index] >= h-index: store that as highest h-index.

#include <vector>
#include <algorithm>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end());

    size_t h_index = 0;
    for (size_t c_idx = 0; c_idx < citations.size(); c_idx++) {
      const int p_citations = citations[c_idx];
      const size_t remaining = citations.size() - c_idx;

      if (p_citations > h_index && (p_citations <= remaining)) {
        h_index = p_citations;
      } else if (remaining > h_index && (p_citations > remaining)) {
        h_index = remaining;
      }
    }

    return h_index;
  }
};

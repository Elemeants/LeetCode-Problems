//
// 438. Find All Anagrams in a String
//
#pragma once

#include <map>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> result;
    std::map<char, std::pair<int, int>> window;

    for (size_t i = 0; i < p.length(); i++) {
      window[p[i]].second++;
    }

    for (size_t i = 0; i < p.length(); i++) {
      if (window.count(s[i]) > 0) {
        window[s[i]].first++;
      }
    }

    if (isSlidingWindowSameAsP(window)) {
      result.push_back(0);
    }

    for (size_t i = p.length(); i < s.length(); i++) {
      const int tail = i - p.length();
      if (window.count(s[tail]) > 0) {
        window[s[tail]].first--;
      }
      if (window.count(s[i]) > 0) {
        window[s[i]].first++;
      }

      if (isSlidingWindowSameAsP(window)) result.push_back(tail + 1);
    }

    return result;
  }

  bool isSlidingWindowSameAsP(std::map<char, std::pair<int, int>> window) {
    return std::all_of(
        window.begin(), window.end(),
        [](const std::pair<int, std::pair<int, int>>& key) -> bool {
          return key.second.first == key.second.second;
        });
  }
};
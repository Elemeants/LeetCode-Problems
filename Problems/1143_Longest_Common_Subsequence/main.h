//
// 1143. Longest Common Subsequence
//
#pragma once

#include <map>
#include <string>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::map<std::pair<int, int>, int> mimo;
    return recursive(mimo, text1, text2, 0, 0);
  }

 private:
  int recursive(std::map<std::pair<int, int>, int>& mimo, std::string& text1,
                std::string& text2, const size_t indexText1,
                const size_t indexText2) {
    if (indexText2 == text2.length() || indexText1 == text1.length()) {
      return 0;
    }

    const auto coord = std::make_pair(indexText1, indexText2);
    if (mimo.count(coord) != 0) {
      return mimo[coord];
    }

    if (text1[indexText1] == text2[indexText2]) {
      mimo[coord] = recursive(mimo, text1, text2, indexText1 + 1, indexText2 + 1) + 1;
    } else {
      mimo[coord] = std::max(recursive(mimo, text1, text2, indexText1, indexText2 + 1),
                      recursive(mimo, text1, text2, indexText1 + 1, indexText2));
    }

    return mimo[coord];
  }
};

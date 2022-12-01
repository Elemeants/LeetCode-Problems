//
// 1704. Determine if String Halves Are Alike
//
#pragma once

#include <string>

class Solution {
 public:
  bool halvesAreAlike(std::string s) {
    int leftCount = 0;
    int rightCount = 0;
    int sizeHalfString = s.length() / 2;

    for (int i = 0; i < sizeHalfString; i++) {
      if (isVowel(s[i])) {
        leftCount++;
      }
      if (isVowel(s[i + sizeHalfString])) {
        rightCount++;
      }
    }
    return leftCount == rightCount;
  }

  bool isVowel(char c) {
    const std::array<char, 5> vowel = {'a', 'e', 'i', 'o', 'u'};
    return std::find(vowel.begin(), vowel.end(), tolower(c)) != vowel.end();
  }
};

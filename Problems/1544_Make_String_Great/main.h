//
// 1544. Make The String Great
//
#pragma once

#include <iostream>
#include <string>

class Solution
{
public:
  std::string makeGood(const std::string& s)
  {
    std::string out = s;
    bool detectedBadChars = false;
    do {
      detectedBadChars = true;
      for (size_t i = 0; i < out.length(); i++) {
        const char current = out[i];
        const char next = out[i + 1];

        if (current != next && (tolower(current) == tolower(next))) {
          out.erase(i, 2);
          detectedBadChars = false;
          i ++;
        }
      }
    } while ((!detectedBadChars));
    return out;
  }
};

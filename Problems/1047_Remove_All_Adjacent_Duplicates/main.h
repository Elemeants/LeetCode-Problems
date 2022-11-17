//
// 1047. Remove All Adjacent Duplicates In String
//
#pragma once

#include <string>
#include <deque>

class Solution
{
public:
  std::string removeDuplicates(std::string s)
  {
    std::deque<char> chars;
    auto it = s.begin();
    chars.push_back(*it++);

    while (it != s.end()) {
      if (chars.size() > 0 && chars.back() == *it) {
        chars.pop_back();
      } else {
        chars.push_back(*it);
      }
      it++;
    }

    std::string output;
    while (chars.size() > 0) {
      output.push_back(chars.front()); chars.pop_front();
    }

    return output;
  }
};

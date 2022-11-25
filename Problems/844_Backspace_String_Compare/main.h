//
// 844. Backspace String Compare
//
#pragma once

#include <string>
#include <deque>

class Solution
{
public:
  bool backspaceCompare(std::string s, std::string t)
  {
    std::deque<char> post_s = processStringWithBackspace(s);
    std::deque<char> post_t = processStringWithBackspace(t);
    return post_s == post_t;
  }

  std::deque<char> processStringWithBackspace(const std::string& str) {
    std::deque<char> processed;
    for (const char& c : str) {
      if (c != '#') {
        processed.push_back(c);
      } else if (!processed.empty()) {
        processed.pop_back();
      }
    }
    return processed;
  }
};
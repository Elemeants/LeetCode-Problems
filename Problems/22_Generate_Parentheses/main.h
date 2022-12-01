//
// 22. Generate Parentheses
//
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result = generateParenthesisN(n);
    return result;
  }

  std::vector<std::string> generateParenthesisN(int n) {
    if (n == 0) {
      return {""};
    }

    std::vector<std::string> parenthesisPrev = generateParenthesis(n - 1);
    std::vector<std::string> current;

    for (size_t i = 0; i < parenthesisPrev.size(); ++i) {
      const std::string& str = parenthesisPrev[i];
      current.push_back("()" + str);
      if (current[current.size() - 1] != str + "()") {
        current.push_back(str + "()");
      }
      if (str.size() > 0) {
        current.push_back("(" + str + ")");
      }
    }

    return current;
  }
};
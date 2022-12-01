//
// 17. Letter Combinations of a Phone Number
//
#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <vector>

class Solution {
  std::map<char, std::vector<char>> digitToLetters = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> result;
    if (digits.size() == 0) {
      return result;
    }

    std::string combination;
    combination.resize(digits.size());
    recursive(digits, result, combination, 0);

    return result;
  }

  void recursive(const std::string& digits, std::vector<std::string>& result,
                 std::string& combination, const size_t digitIndex) {
    if (digitIndex == digits.size()) {
      result.push_back(combination);
      return;
    }

    for (const char c : digitToLetters[digits[digitIndex]]) {
      combination[digitIndex] = c;
      recursive(digits, result, combination, digitIndex + 1);
    }
  }
};

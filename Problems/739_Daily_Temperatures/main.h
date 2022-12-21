//
// 739. Daily Temperatures
//
#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::stack<int, std::deque<int>> stack;
    std::vector<int> result(temperatures.size());

    for (size_t day = 0; day < temperatures.size(); day++) {
      const int temperature = temperatures[day];
      // std::cout << temperature << " -> " << std::endl;
      insertAndUpdate(stack, temperatures, result, temperature, day);
      // std::cout << std::endl;
    }

    return result;
  }

  void insertAndUpdate (
    std::stack<int, std::deque<int>>& stack,
    std::vector<int>& temperatures,
    std::vector<int>& days,
    const int temperature,
    const int day
  ) {
    if (stack.empty()) {
      stack.push(day);
      return;
    }

    int day_temperature = temperatures[stack.top()];
    while (!stack.empty() && day_temperature < temperature) {
      const int day_index = stack.top();
      day_temperature = temperatures[day_index];
      if (day_temperature >= temperature) {
        break;
      }
      stack.pop();
      std::cout << "day: " << day << "/" << temperature << " from: " << day_index << "/" << day_temperature << std::endl;
      days[day_index] = (day - day_index);
    }
    stack.push(day);
  }
};
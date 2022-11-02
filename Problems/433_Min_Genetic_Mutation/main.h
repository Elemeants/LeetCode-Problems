//
// 433. Min Genetic Mutation
//
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_set>
#include <queue>

class Solution
{
  const int NO_FOUND = -1;

public:
  int minMutation(
      const std::string &start,
      const std::string &end,
      const std::vector<std::string> &bank)
  {
    if (bank.size() == 1)
    {
      if (isOneMutationValid(start, end) && end == bank[0])
      {
        return 1;
      }
      return NO_FOUND;
    }

    std::unordered_set<std::string> nodesFounded;
    std::queue<
      std::pair<std::string, int>,
      std::deque<std::pair<std::string, int>>
      > queue;
    queue.push(std::make_pair(start, 0));

    while (queue.size() > 0) {
      const auto i = queue.front();
      nodesFounded.insert(i.first);
      queue.pop();

      for (const auto& item : bank) {
        if (isOneMutationValid(i.first, item) && nodesFounded.count(item) == 0) {
          if (item == end) {
            return i.second + 1;
          }
          queue.push(std::make_pair(item, i.second + 1));
        }
      }
    }

    return NO_FOUND;
  }

  bool isOneMutationValid(const std::string &original, const std::string &mutated)
  {
    bool one_diff = false;
    for (size_t i = 0; i < original.size(); i++)
    {
      if (original[i] != mutated[i])
      {
        if (one_diff)
        {
          return false;
        }
        one_diff = true;
      }
    }
    return one_diff;
  }
};

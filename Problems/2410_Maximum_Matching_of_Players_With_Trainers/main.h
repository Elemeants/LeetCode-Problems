//
// 2410. Maximum Matching of Players With Trainers
//
#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  int matchPlayersAndTrainers(std::vector<int>& players,
                              std::vector<int>& trainers) {
    std::sort(players.begin(), players.end(), std::greater<int>());
    std::sort(trainers.begin(), trainers.end(), std::greater<int>());
    size_t players_pointer = 0;
    size_t trainers_pointer = 0;
    size_t matches = 0;
    while (true) {
      if (trainers_pointer >= trainers.size() || players_pointer >= players.size()) {
        break;
      }

      if (players[players_pointer] <= trainers[trainers_pointer]) {
        matches++;
        trainers_pointer++;
      }
      players_pointer++;
    }

    return matches;
  }
};

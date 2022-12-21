//
// 841. Keys and Rooms
//
#pragma once

#include <vector>
#include <set>
#include <deque>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  bool canVisitAllRooms(vector2D& rooms) {
    std::set<int> keys;
    std::deque<int> nodes;
    nodes.push_back(0);
    keys.insert(0);

    while (!nodes.empty()) {
      const int room_index = nodes.back(); nodes.pop_back();
      
      for (const int key : rooms[room_index]) {
        if (keys.find(key) != keys.end()) {
          continue;
        }
        keys.insert(key);
        nodes.push_back(key);
      }
    }

    return keys.size() == rooms.size();
  }
};
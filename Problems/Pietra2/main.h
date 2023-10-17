#pragma once

#include <map>
#include <queue>
#include <vector>
#include <iostream>

class Solution {
 public:
  std::vector<int> frequencyOfMaxNewUsers(const std::vector<int> newUsersPerDay,
                                          const std::vector<int> queries) {
    std::map<int, int> repeatedMaxPerIndex;
    std::vector<int> uniqueElements(queries);
    std::vector<int> result(queries);

    std::sort(uniqueElements.begin(), uniqueElements.end(), std::greater<int>());
    auto it = std::unique(uniqueElements.begin(), uniqueElements.end());
    uniqueElements.resize(std::distance(uniqueElements.begin(), it));
    it = uniqueElements.begin();

    int latestMax = -1;
    int count = 1;

    for (int i = (newUsersPerDay.size() - 1); i >= 0; i--) {
      const int& noUsers = newUsersPerDay[i];
      if (noUsers == latestMax) {
        count++;
      }
      latestMax = std::max(latestMax, noUsers);
      if (*it == (i + 1)) {
        repeatedMaxPerIndex[i] = count;
        it++;
      }
    }

    for (int i = 0; i < queries.size(); i++) {
      result[i] = repeatedMaxPerIndex[queries[i] - 1];
    }

    return result;
  }
};

/*

new_users_per_day = [5, 4, 5, 3, 2]
q = [5, 1, 1, 2, 5]                              -> [5, 2, 1]

            [2]  { 2: 1}                         -> 2: 1
         [3, 2]  { 2: 1, 3: 1}                   -> 3: 1
      [5, 3, 2]  { 2: 1, 3: 1, 5: 1}             -> 5: 1
   [4, 5, 3, 2]  { 2: 1, 3: 1, 4: 1, 5: 1}       -> 5: 1
[5, 4, 5, 3, 2]  { 2: 1, 3: 1, 4: 1, 5: 1, 5: 2} -> 5: 2

            [2]  { 2: 1}                         -> 2: 1
         [3, 2]  { 2: 1, 3: 1}                   -> 3: 1
[5, 4, 5, 3, 2]  { 2: 1, 3: 1, 4: 1, 5: 1, 5: 2} -> 5: 2

*/

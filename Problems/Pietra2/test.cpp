/**
At Company_X we are trying to improve our marketing strategies querying on a fixed ranges when he had most new users so we can find patterns to run our campaigns and find out later what we did those days well.

For a given array of integers representing number of new users per day, determine the maximum value of new users in the segment from each index to the highest index element, inclusive. After that has been determined, determine the number of times that highest value of new users occurs in the segment. A number of queries will then be given, where each query represents an index within the array. Create a return array with one value for each query. the number of times the maximum value occurs in a segment starting at that index

Example
new_users_per_day = [5, 4, 5, 3, 2]
q = [1, 2, 3, 4, 5]

Note: The numbers array indexes are from 1 to n where n is the length of the array.

For the first query, the index is 1. The segment starting at index 1 is [5, 4, 5, 3, 2]. The highest value is 5, and it occurs 2 times. result = [2]
For the second query, the Index is 2. The segment staritng at Index 2 is [4, 5, 3, 2]. The highest value is 5, and it occurs 1 time. result = [2, 1]
In each of the remaining segments queried, [5, 3, 2], [3, 2], and [2], there is only one occurrence of a highest value so a 1 is appended to result for each query.
The final array returned is [2, 1, 1, 1, 1].

Function Description:

Complete the frequencyOfMaxNewUsers function in the editor below. The function must return an integer array that denotes the answers to the query array.

frequencyOfMaxNewUsers has two parameters:
int[n] new_users_per_day: an integer array that contains the values of the n new users that day. 
int[m] q: an integer array that contains the index values for each query

Returns:
int[m]: an integer array with the answers to each query, aligned by index

Constraints
• 1 ≤ n, m       ≤ 10ˆ5
• 1 ≤ numbers[i] ≤ 10ˆ6
• 1 <= q[j] <= n
 */

#include <gtest/gtest.h>
#include "main.h"

TEST(MockInterview2, InitialCase) {
  const std::vector<int> expected = {2, 1, 1, 1, 1};
  std::vector<int> result = Solution().frequencyOfMaxNewUsers({5, 4, 5, 3, 2}, {1, 2, 3, 4, 5});
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], result[i]) << "Unmatch on index " << i;
  }
}

TEST(MockInterview2, InitialCase2) {
  const std::vector<int> expected = {2, 1, 1};
  std::vector<int> result = Solution().frequencyOfMaxNewUsers({2, 1, 2}, {1, 2, 3});
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(expected[i], result[i]) << "Unmatch on index " << i;
  }
}

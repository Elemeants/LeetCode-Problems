//
// 2044. Count Number of Maximum Bitwise-OR Subsets
//
#pragma once

/**

Ok so basically I'll receive a list of numbers and I have to
generate the permutations of the array.

And then for each permutation, calculate the bitwise-or number
and for the maximum value calculate how many subsets it has?
> What means "different non-empty subsets"?

So a brute force solution I can think is that one.
- Run the permutations of the array
- For each permuation calculate its bitwise value.
- Using a map, store as a key the value of the bitwise operation
  and the map value is the count of subsets.
- Get the max key value in the map, and return its value.

> This can be bad at a large scale.

!How to optimize this?

[3, 2, 1, 5] seems a good example.

Possible permutations
> [3]
> [2]
> [3, 2]
> [1]
> [3, 1]
> [2, 1]
> [3, 2, 1]
> [5]
> [3, 5]
> [2, 5]
> [3, 2, 5]
> [1, 5]
> [3, 1, 5]
> [2, 1, 5]
> [3, 2, 1, 5]

I mean, it is always like `nums[i] & (nums[i+1:nums.size()])`
so I should be able to store some permutations so we do not
repeat them.

[5] + []  -> max: 5, count: 1, store: [(5: 1)]
[1] + [5] -> max: 6, count: 1, store: [(5: 1), ([1, 5]: 1), (5: 1)]
[2] + [1, 5] ->

// I need to think more about this, but will implement the bruteforce one
Basically its a binary count, to build the mask for the elements, then
iterate them and store the result.

 */

#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  int countMaxOrSubsets(const std::vector<int>& nums) {
    const size_t num_permutations =
        (size_t)std::round(std::pow(2, nums.size()));
    std::map<size_t, size_t> subsets_count;

    size_t bits_size = 0;
    for (size_t mask = 0b1; mask < num_permutations; mask++) {
      if ((mask & (mask - 1)) == 0) {
        bits_size++;
      }

      size_t bitwise_sum = 0;
      for (size_t bit = 0; bit < bits_size; bit++) {
        if ((((size_t)1 << bit) & mask) >> bit == 0) {
          continue;
        }
        bitwise_sum |= nums[bit];
      }

      const std::map<size_t, size_t>::iterator it =
          subsets_count.find(bitwise_sum);
      if (it == subsets_count.end()) {
        subsets_count[bitwise_sum] = 1;
      } else {
        subsets_count[bitwise_sum]++;
      }
    }

    return (int)subsets_count.rbegin()->second;
  }
};

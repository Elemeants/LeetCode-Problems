//
// 77. Combinations
//
#pragma once

#include <vector>

using listOfCombinations = std::vector<std::vector<int>>;

class Solution
{
public:
  //
  // Calculate the list of possible combinations from `[1..n]` on tuples of lenght `k`
  //
  listOfCombinations combine(const int n, const int k)
  {
    listOfCombinations result = {};

    //
    // Case when there are only one combination
    //
    if (n == k)
    {
      std::vector<int> comb;
      comb.resize(k);
      for (int e = 1; e <= n; ++e)
      {
        comb[e - 1] = e;
      }
      result.push_back(comb);
      return result;
    }

    //
    // No spaces for combinations.
    //
    if (k == 1)
    {
      for (int e = 1; e <= n; ++e)
      {
        result.push_back({e});
      }
      return result;
    }

    //
    // Do combinations
    //
    do_combinations_recursive(result, n, k);

    return result;
  }

  void do_combinations_recursive(
      listOfCombinations &result,
      const int n,
      const int k)
  {
    std::vector<int> v;
    v.resize(k);

    generate_recusive_fors(result, v, 0, 0, n, k);
  }

  void generate_recusive_fors(
      listOfCombinations &result,
      std::vector<int> &combination,
      const int index,
      const int prev_n,
      const int n,
      const int k)
  {
    for (int s = prev_n + 1; s <= n; ++s)
    {
      combination[index] = s;
      if (index == (k - 1))
      {
        result.push_back(combination);
      }
      else
      {
        generate_recusive_fors(result, combination, index + 1, s, n, k);
      }
    }
  }
};
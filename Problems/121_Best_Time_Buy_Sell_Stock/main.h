//
// 121. Best Time to Buy and Sell Stock
//
#pragma once

#include <algorithm>
#include <vector>

class Solution
{
public:
  int maxProfit(std::vector<int> &prices)
  {
    int maxProfit = 0;
    if (prices.size() == 1) return 0;

    int localMinimum = prices[0];

    for (const int &price : prices) {
      localMinimum = std::min(localMinimum, price);
      maxProfit = std::max(maxProfit, price - localMinimum);
    }

    return maxProfit;
  }
};

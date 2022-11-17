#include <gtest/gtest.h>
#include "main.h"

TEST(Test121, Case1)
{
  std::vector<int> prices = {7, 6, 5, 4};

  EXPECT_EQ(Solution().maxProfit(prices), 0);
}

TEST(Test121, Case2)
{
  std::vector<int> prices = {1, 2, 3, 4};

  EXPECT_EQ(Solution().maxProfit(prices), 3);
}

TEST(Test121, Case3)
{
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  EXPECT_EQ(Solution().maxProfit(prices), 5);
}

TEST(Test121, SingleEntryShouldNotHaveAnyProfit)
{
  std::vector<int> prices = {7};

  EXPECT_EQ(Solution().maxProfit(prices), 0);
}

TEST(Test121, TwoEntriesAndNoProfit)
{
  std::vector<int> prices = {7, 4};

  EXPECT_EQ(Solution().maxProfit(prices), 0);
}

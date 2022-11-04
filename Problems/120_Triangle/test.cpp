#include <gtest/gtest.h>
#include "main.h"

TEST(Test120, OneLevel)
{
  std::vector<std::vector<int>> triangle = {{-10}};
  EXPECT_EQ(Solution().minimumTotal(triangle), -10);
}

TEST(Test120, FourLevel)
{
  std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  EXPECT_EQ(Solution().minimumTotal(triangle), 11);
}

TEST(Test120, WithNegativeValues)
{
  std::vector<std::vector<int>> triangle = {
      {-1},
      {2, 3},
      {1, -1, -3}};
  EXPECT_EQ(Solution().minimumTotal(triangle), -1);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Test198, IfOnlyOneHouseReturnItValue)
{
  std::vector<int> input = { 10 };
  EXPECT_EQ(Solution().rob(input), 10);
}

TEST(Test198, IfThereAreTwoHousesReturnMaxValue)
{
  std::vector<int> input = { 10, 20 };
  EXPECT_EQ(Solution().rob(input), 20);
}

TEST(Test198, ThreeHouses)
{
  std::vector<int> input = { 10, 20, 30 };
  EXPECT_EQ(Solution().rob(input), 30);
}

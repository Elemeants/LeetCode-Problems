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
  EXPECT_EQ(Solution().rob(input), 40);
}

TEST(Test198, DefaultTest) {
  std::vector<int> input = { 2,7,9,3,1 };
  EXPECT_EQ(Solution().rob(input), 12);
}

TEST(Test198, DefaultTest2) {
  std::vector<int> input = { 1,2,3,1 };
  EXPECT_EQ(Solution().rob(input), 4);
}

TEST(Test198, TestForTimeLimitExcedeed)
{
  std::vector<int> input = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
  EXPECT_EQ(Solution().rob(input), 3365);
}

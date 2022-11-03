#include <gtest/gtest.h>
#include "main.h"

TEST(TestFactorial, DefaultTest)
{
  EXPECT_EQ(Solution().factorial(1), 1);
  EXPECT_EQ(Solution().factorial(2), 2);
  EXPECT_EQ(Solution().factorial(3), 6);
  EXPECT_EQ(Solution().factorial(4), 24);
  EXPECT_EQ(Solution().factorial(5), 120);
  EXPECT_EQ(Solution().factorial(6), 720);
}

TEST(Test46, DefaultTest)
{
  std::vector<int> input = {1, 2, 3};
  listOfPermutations expected = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  EXPECT_EQ(Solution().permute(input), expected);
}

TEST(Test46, InputOfSize2OnlyNeedToSwap)
{
  std::vector<int> input = {0, 1};
  listOfPermutations expected = {{0, 1}, {1, 0}};
  EXPECT_EQ(Solution().permute(input), expected);
}

TEST(Test46, InputOfSizeOneDoNothing)
{
  std::vector<int> input = {1};
  listOfPermutations expected = {{1}};
  EXPECT_EQ(Solution().permute(input), expected);
}

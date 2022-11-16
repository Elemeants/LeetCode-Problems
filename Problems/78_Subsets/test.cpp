#include <gtest/gtest.h>
#include "main.h"

TEST(Test78, Case1)
{
  std::vector<int> input = {1, 2, 3};
  vector2D expected = {{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}};
  EXPECT_EQ(Solution().subsets(input), expected);
}

TEST(Test78, Case2)
{
  std::vector<int> input = {0};
  vector2D expected = {{}, {0}};
  EXPECT_EQ(Solution().subsets(input), expected);
}

TEST(Test78, WithTwoVariablesShouldReturn3PossibleSubsets)
{
  std::vector<int> input = {0, 1};
  vector2D expected = {{}, {0}, {0, 1}, {1}};
  EXPECT_EQ(Solution().subsets(input), expected);
}

TEST(Test78, WithUnorderedValuesAndNegatives)
{
  std::vector<int> input = {-5, 0, -6};
  vector2D expected = {{}, {-6}, {-6, -5}, {-6, -5, 0}, {-6, 0}, {-5}, {-5, 0}, {0}};
  EXPECT_EQ(Solution().subsets(input), expected);
}

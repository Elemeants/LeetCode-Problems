#include <gtest/gtest.h>
#include "main.h"

TEST(Test39, Case1) {
  std::vector<int> candidates = {2, 3, 6, 7};
  const int target = 7;
  const vector2D expected = {
    {2, 2, 3},
    {7}
  };
  EXPECT_EQ(Solution().combinationSum(candidates, target), expected);
}

TEST(Test39, Case2) {
  std::vector<int> candidates = {2, 3, 5};
  const int target = 8;
  const vector2D expected = {
    {2, 2, 2, 2},
    {2, 3, 3},
    {3, 5}
  };
  EXPECT_EQ(Solution().combinationSum(candidates, target), expected);
}

TEST(Test39, Case3) {
  std::vector<int> candidates = {2};
  const int target = 1;
  const vector2D expected = {

  };
  EXPECT_EQ(Solution().combinationSum(candidates, target), expected);
}

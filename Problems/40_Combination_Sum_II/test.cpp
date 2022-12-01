#include <gtest/gtest.h>
#include "main.h"

TEST(Test39, Case1) {
  std::vector<int> candidates = {10,1,2,7,6,1,5};
  const int target = 8;
  const vector2D expected = {
    {1, 1, 6},
    {1, 2, 5},
    {1, 7},
    {2, 6}
  };
  EXPECT_EQ(Solution().combinationSum2(candidates, target), expected);
}

TEST(Test39, Case2) {
  std::vector<int> candidates = {2,5,2,1,2};
  const int target = 5;
  const vector2D expected = {
    {1, 2, 2},
    {5}
  };
  EXPECT_EQ(Solution().combinationSum2(candidates, target), expected);
}

TEST(Test39, Case3) {
  std::vector<int> candidates = {2, 3, 6, 7};
  const int target = 7;
  const vector2D expected = {
    {7}
  };
  EXPECT_EQ(Solution().combinationSum2(candidates, target), expected);
}


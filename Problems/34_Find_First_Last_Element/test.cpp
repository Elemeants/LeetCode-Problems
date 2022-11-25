#include <gtest/gtest.h>
#include "main.h"

TEST(Test34, Case1)
{
  int target = 8;
  std::vector<int> input = {5, 7, 7, 8, 8, 10};
  std::vector<int> expected = {3, 4};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

TEST(Test34, Case2)
{
  int target = 6;
  std::vector<int> input = {5, 7, 7, 8, 8, 10};
  std::vector<int> expected = {-1, -1};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

TEST(Test34, Case3)
{
  int target = 0;
  std::vector<int> input = {};
  std::vector<int> expected = {-1, -1};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}


TEST(Test34, CaseSearchLeftEdge)
{
  int target = 4;
  std::vector<int> input = {1, 2, 3, 4, 4, 4, 4, 4, 6};
  std::vector<int> expected = {3, 7};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

TEST(Test34, CaseGeneratedOverflow)
{
  int target = 0;
  std::vector<int> input = {1};
  std::vector<int> expected = {-1, -1};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

TEST(Test34, CaseGeneratedOverflow2)
{
  int target = 1;
  std::vector<int> input = {2, 2};
  std::vector<int> expected = {-1, -1};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

TEST(Test34, WrongCase)
{
  int target = 1;
  std::vector<int> input = {1, 2, 3};
  std::vector<int> expected = {0, 0};
  EXPECT_EQ(Solution().searchRange(input, target), expected);
}

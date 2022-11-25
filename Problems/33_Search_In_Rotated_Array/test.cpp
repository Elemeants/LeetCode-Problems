#include <gtest/gtest.h>
#include "main.h"

TEST(Test34, Case1)
{
  int target = 0;
  std::vector<int> input = {4,5,6,7,0,1,2};
  EXPECT_EQ(Solution().search(input, target), 4);
}

TEST(Test34, Case2)
{
  int target = 3;
  std::vector<int> input = {4,5,6,7,0,1,2};
  EXPECT_EQ(Solution().search(input, target), -1);
}

TEST(Test34, Case3)
{
  int target = 0;
  std::vector<int> input = {1};
  EXPECT_EQ(Solution().search(input, target), -1);
}

TEST(Test34, Case4)
{
  int target = 0;
  std::vector<int> input = {3, 1};
  EXPECT_EQ(Solution().search(input, target), -1);
}

TEST(Test34, CaseOffsetOverflow)
{
  int target = 0;
  std::vector<int> input = {1, 3};
  EXPECT_EQ(Solution().search(input, target), -1);
}

TEST(Test34, EdgeCase1)
{
  int target = 2;
  std::vector<int> input = {1, 3};
  EXPECT_EQ(Solution().search(input, target), -1);
}

TEST(Test34, EdgeCase2)
{
  int target = 2;
  std::vector<int> input = {3, 1};
  EXPECT_EQ(Solution().search(input, target), -1);
}

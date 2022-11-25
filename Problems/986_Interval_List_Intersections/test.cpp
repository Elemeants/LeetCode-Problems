#include <gtest/gtest.h>
#include "main.h"

TEST(Test986, Case1)
{
  vector2D firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector2D secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  vector2D expected = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};

  EXPECT_EQ(Solution().intervalIntersection(firstList, secondList), expected);
}

TEST(Test986, Case2)
{
  vector2D firstList = {{1, 3}, {5, 9}};
  vector2D secondList = {};
  vector2D expected = {};

  EXPECT_EQ(Solution().intervalIntersection(firstList, secondList), expected);
}

TEST(Test986, Case3)
{
  vector2D firstList = {{5, 10}};
  vector2D secondList = {{3, 10}};
  vector2D expected = {{5, 10}};

  EXPECT_EQ(Solution().intervalIntersection(firstList, secondList), expected);
}

TEST(Test986, Case4)
{
  vector2D firstList = {{5, 10}};
  vector2D secondList = {{5, 6}};
  vector2D expected = {{5, 6}};

  EXPECT_EQ(Solution().intervalIntersection(firstList, secondList), expected);
}

TEST(Test986, Case5)
{
  vector2D firstList = {{3, 10}};
  vector2D secondList = {{5, 10}};
  vector2D expected = {{5,10}};

  EXPECT_EQ(Solution().intervalIntersection(firstList, secondList), expected);
}

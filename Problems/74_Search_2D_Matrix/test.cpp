#include <gtest/gtest.h>
#include "main.h"

TEST(Test74, Case1) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 3;
  EXPECT_TRUE(Solution().searchMatrix(input, target));
}

TEST(Test74, Case2) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 13;
  EXPECT_FALSE(Solution().searchMatrix(input, target));
}

TEST(Test74, Case3) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 0;
  EXPECT_FALSE(Solution().searchMatrix(input, target));
}

TEST(Test74, Case4) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 70;
  EXPECT_FALSE(Solution().searchMatrix(input, target));
}

TEST(Test74, Case5) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 9;
  EXPECT_FALSE(Solution().searchMatrix(input, target));
}

TEST(Test74, Case6) {
  const vector2D input = {
    {1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,60}
  };
  const int target = 60;
  EXPECT_TRUE(Solution().searchMatrix(input, target));
}

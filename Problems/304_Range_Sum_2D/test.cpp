#include <gtest/gtest.h>

#include "main.h"

TEST(Test304, Case1) {
  const vector2D input = {{3, 0, 1, 4, 2},
                          {5, 6, 3, 2, 1},
                          {1, 2, 0, 1, 5},
                          {4, 1, 0, 1, 7},
                          {1, 0, 3, 0, 5}};
  NumMatrix sumMatrix(input);
  EXPECT_EQ(sumMatrix.sumRegion(2, 1, 4, 3), 8);
  EXPECT_EQ(sumMatrix.sumRegion(1, 1, 2, 2), 11);
  EXPECT_EQ(sumMatrix.sumRegion(1, 2, 2, 4), 12);
}

TEST(Test304, Case2) {
  const vector2D input = {{1, 2, 3},
                          {2, 2, 3},
                          {3, 3, 3}};
  NumMatrix sumMatrix(input);
  EXPECT_EQ(sumMatrix.sumRegion(0, 0, 1, 1), 7);
  EXPECT_EQ(sumMatrix.sumRegion(1, 1, 2, 2), 11);
  EXPECT_EQ(sumMatrix.sumRegion(1, 0, 2, 1), 10);
}

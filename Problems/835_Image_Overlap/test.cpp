#include <gtest/gtest.h>
#include "main.h"

TEST(Test835, MatrixOfNoSizeShouldReturn0)
{
  binaryMatrix img1;
  binaryMatrix img2;
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 0);
}

TEST(Test835, MatrixOfSizeOneExpectOne)
{
  binaryMatrix img1 = {{1}};
  binaryMatrix img2 = {{1}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 1);
}

TEST(Test835, MatrixOfSizeOneExpectZero)
{
  binaryMatrix img1 = {{0}};
  binaryMatrix img2 = {{0}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 0);
}

TEST(Test835, BothMatrixEqual)
{
  binaryMatrix img1 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  binaryMatrix img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 3);
}

TEST(Test835, ShiftOnX)
{
  binaryMatrix img1 = {{0, 1, 1}, {0, 0, 1}, {0, 0, 0}};
  binaryMatrix img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 3);
}

TEST(Test835, ShiftOnY)
{
  binaryMatrix img1 = {{0, 0, 0}, {1, 1, 0}, {0, 1, 0}};
  binaryMatrix img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 3);
}

TEST(Test835, ShiftOnX_Y)
{
  binaryMatrix img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
  binaryMatrix img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 3);
}

TEST(Test835, ShiftNegative)
{
  binaryMatrix img1 = {
      {0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0}};
  binaryMatrix img2 = {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0}};
  EXPECT_EQ(Solution().largestOverlap(img1, img2), 1);
}

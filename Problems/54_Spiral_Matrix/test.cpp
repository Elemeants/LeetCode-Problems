#include <gtest/gtest.h>
#include "main.h"

TEST(Test54, MatrixOf1x1ShouldReturnSingleValue)
{
  vector2D matrix = {
      {1}};
  std::vector<int> expected = {1};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

TEST(Test54, Matrix1xNShoulrReturnASingleRow)
{
  vector2D matrix = {
      {1, 2, 3, 4, 5}};
  std::vector<int> expected = {1, 2, 3, 4, 5};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

TEST(Test54, TwoRowsShouldReturnFirstRowThenReversedSecondRow)
{
  vector2D matrix = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10}};
  std::vector<int> expected = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

TEST(Test54, SquareCase)
{
  vector2D matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  std::vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

TEST(Test54, RectangleCase)
{
  vector2D matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}};
  std::vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

TEST(Test54, Square4x4)
{
  vector2D matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};

  std::vector<int> expected = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};

  EXPECT_EQ(Solution().spiralOrder(matrix), expected);
}

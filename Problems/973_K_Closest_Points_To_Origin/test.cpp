#include <gtest/gtest.h>
#include "main.h"

TEST(Test973, Case1) {
  vector2D input = {{1, 3}, {-2, 2}};
  const int k = 1;
  vector2D expected = {{-2, 2}};
  EXPECT_EQ(Solution().kClosest(input, k), expected);
}

TEST(Test973, Case2) {
  vector2D input = {{3, 3}, {5, -1}, {-2, 4}};
  const int k = 2;
  vector2D expected = {{3, 3}, {-2, 4}};
  EXPECT_EQ(Solution().kClosest(input, k), expected);
}

TEST(Test973, Case3) {
  vector2D input = {{2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}};
  const int k = 1;
  vector2D expected = {{1, 1}};
  EXPECT_EQ(Solution().kClosest(input, k), expected);
}

TEST(Test973, Case4) {
  vector2D input = {{-5, 4}, {-6, 5}, {4, 6}};
  const int k = 2;
  vector2D expected = {{-5, 4}, {4, 6}};
  EXPECT_EQ(Solution().kClosest(input, k), expected);
}
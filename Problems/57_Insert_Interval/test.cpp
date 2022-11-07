#include <gtest/gtest.h>
#include <vector>
#include "main.h"

TEST(Test57, Case1) {
  vector2D intervals = {{1,3},{6,9}};
  std::vector<int> new_interval = {2, 5};

  const vector2D expected = {{1,5},{6,9}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, Case2) {
  vector2D intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12, 16}};
  std::vector<int> new_interval = {4, 8};
  const vector2D expected = {{1, 2}, {3, 10}, {12, 16}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, Empty) {
  vector2D intervals = {};
  std::vector<int> new_interval = {4, 8};
  const vector2D expected = {{4, 8}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, InnerNoOverlap) {
  vector2D intervals = {{1,3},{6,9}};
  std::vector<int> new_interval = {4, 5};
  const vector2D expected = {{1,3},{4, 5},{6,9}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, LeftNoOverlap) {
  vector2D intervals = {{4,5},{6,9}};
  std::vector<int> new_interval = {1, 3};
  const vector2D expected = {{1,3},{4, 5},{6,9}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, RightNoOverlap) {
  vector2D intervals = {{1,3},{4,5}};
  std::vector<int> new_interval = {7, 9};
  const vector2D expected = {{1,3},{4, 5},{7,9}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}

TEST(Test57, InnerOverLap) {
  vector2D intervals = {{1,5}};
  std::vector<int> new_interval = {2, 3};
  const vector2D expected = {{1,5}};
  EXPECT_EQ(Solution().insert(intervals, new_interval), expected);
}
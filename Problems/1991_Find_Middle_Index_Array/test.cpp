#include <gtest/gtest.h>
#include "main.h"

TEST(Test1991, Case1) {
  std::vector<int> input = {2,3,-1,8,4};
  EXPECT_EQ(Solution().findMiddleIndex(input), 3);
}

TEST(Test1991, Case2) {
  std::vector<int> input = {1,-1,4};
  EXPECT_EQ(Solution().findMiddleIndex(input), 2);
}

TEST(Test1991, Case3) {
  std::vector<int> input = {2,5};
  EXPECT_EQ(Solution().findMiddleIndex(input), -1);
}

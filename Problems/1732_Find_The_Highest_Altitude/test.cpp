#include <gtest/gtest.h>
#include "main.h"

TEST(Test1732, Case1) {
  std::vector<int> input = {-5,1,5,0,-7};
  EXPECT_EQ(Solution().largestAltitude(input), 1);
}

TEST(Test1732, Case2) {
  std::vector<int> input = {-4,-3,-2,-1,4,3,2};
  EXPECT_EQ(Solution().largestAltitude(input), 0);
}

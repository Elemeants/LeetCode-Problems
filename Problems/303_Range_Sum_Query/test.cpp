#include <gtest/gtest.h>
#include "main.h"

TEST(Test303, Case1) {
  std::vector<int> input = {-2,0,3,-5,2,-1};
  NumArray array(input);
  EXPECT_EQ(array.sumRange(0, 2), 1);
  EXPECT_EQ(array.sumRange(2, 5), -1);
  EXPECT_EQ(array.sumRange(0, 5), -3);
}

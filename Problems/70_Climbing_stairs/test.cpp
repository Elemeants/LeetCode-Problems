#include <gtest/gtest.h>
#include "main.h"

TEST(Test70, BaseSequence) {
  Solution sol;
  EXPECT_EQ(sol.climbStairs(2), 2);
  EXPECT_EQ(sol.climbStairs(3), 3);
  EXPECT_EQ(sol.climbStairs(4), 5);
  EXPECT_EQ(sol.climbStairs(5), 8);
  EXPECT_EQ(sol.climbStairs(6), 13);
}

TEST(Test70, LongTimeExecution) {
  Solution sol;
  EXPECT_EQ(sol.climbStairs(44), 1134903170);
}
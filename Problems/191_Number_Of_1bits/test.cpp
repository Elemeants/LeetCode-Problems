#include <gtest/gtest.h>
#include "main.h"

TEST(Test191, Case1) {
  EXPECT_EQ(Solution().hammingWeight(0b00000000000000000000000000001011), 3);
}

TEST(Test191, Case2) {
  EXPECT_EQ(Solution().hammingWeight(0b00000000000000000000000010000000), 1);
}

TEST(Test191, Case3) {
  EXPECT_EQ(Solution().hammingWeight(0b11111111111111111111111111111101), 31);
}

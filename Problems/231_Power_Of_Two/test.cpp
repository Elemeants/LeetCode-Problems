#include <gtest/gtest.h>
#include "main.h"

TEST(Test231, Case1) {
  EXPECT_TRUE(Solution().isPowerOfTwo(1));
}

TEST(Test231, Case2) {
  EXPECT_TRUE(Solution().isPowerOfTwo(16));
}

TEST(Test231, Case3) {
  EXPECT_FALSE(Solution().isPowerOfTwo(3));
}

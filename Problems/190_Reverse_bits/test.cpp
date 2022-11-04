#include <gtest/gtest.h>
#include "main.h"

TEST(Test190, Case1) {
  EXPECT_EQ(Solution().reverseBits(0b00000010100101000001111010011100),
                                   0b00111001011110000010100101000000);
}

TEST(Test190, Case2) {
  EXPECT_EQ(Solution().reverseBits(0b11111111111111111111111111111101),
                                   0b10111111111111111111111111111111);
}

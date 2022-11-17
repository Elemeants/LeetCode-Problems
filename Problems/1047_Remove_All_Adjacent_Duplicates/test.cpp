#include <gtest/gtest.h>
#include "main.h"

TEST(Test1047, Case1) {
  EXPECT_EQ(Solution().removeDuplicates("abbaca"), "ca");
}

TEST(Test1047, Case2) {
  EXPECT_EQ(Solution().removeDuplicates("azxxzy"), "ay");
}

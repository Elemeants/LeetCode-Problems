#include <gtest/gtest.h>
#include "main.h"

TEST(Test844, Case1) {
  EXPECT_TRUE(Solution().backspaceCompare("ab#c", "ad#c"));
}

TEST(Test844, Case2) {
  EXPECT_TRUE(Solution().backspaceCompare("ab##", "c#d#"));
}

TEST(Test844, Case3) {
  EXPECT_FALSE(Solution().backspaceCompare("a#c", "b"));
}

TEST(Test844, Case4) {
  EXPECT_TRUE(Solution().backspaceCompare("a##c", "#a#c"));
}

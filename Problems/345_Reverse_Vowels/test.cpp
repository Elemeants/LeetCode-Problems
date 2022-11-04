#include <gtest/gtest.h>
#include "main.h"

TEST(Test345, Case1) {
  EXPECT_EQ(Solution().reverseVowels("hello"), "holle");
}

TEST(Test345, Case2) {
  EXPECT_EQ(Solution().reverseVowels("leetcode"), "leotcede");
}

TEST(Test345, Case3) {
  EXPECT_EQ(Solution().reverseVowels("aA"), "Aa");
}

TEST(Test345, Case4) {
  EXPECT_EQ(Solution().reverseVowels("axA"), "Axa");
}

TEST(Test345, Case5) {
  EXPECT_EQ(Solution().reverseVowels("aeiou"), "uoiea");
}

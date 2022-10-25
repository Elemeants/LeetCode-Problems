#include <gtest/gtest.h>
#include "main.h"

TEST(TestLongestSubstring, BaseCase) {
    EXPECT_EQ (Solution().lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(TestLongestSubstring, AllTheSameCharacters) {
    EXPECT_EQ (Solution().lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(TestLongestSubstring, CheckForSubstringNotSubsequence) {
    EXPECT_EQ (Solution().lengthOfLongestSubstring("pwwkew"), 3);
}

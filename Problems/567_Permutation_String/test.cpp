#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    EXPECT_TRUE(Solution().checkInclusion(s1, s2));
}

TEST(Testing, ShouldReturnFalseNoPermutation)
{
    std::string s1 = "ab";
    std::string s2 = "eidboaoo";
    EXPECT_FALSE(Solution().checkInclusion(s1, s2));
}

TEST(Testing, ShouldReturnFalseIfS1IsBigger)
{
    std::string s1 = "abas";
    std::string s2 = "ei";
    EXPECT_FALSE(Solution().checkInclusion(s1, s2));
}

TEST(Testing, BothAreTheSameSizeNegative)
{
    std::string s1 = "ab";
    std::string s2 = "ei";
    EXPECT_FALSE(Solution().checkInclusion(s1, s2));
}

TEST(Testing, BothAreTheSameSizePositive)
{
    std::string s1 = "ab";
    std::string s2 = "ba";
    EXPECT_TRUE(Solution().checkInclusion(s1, s2));
}


TEST(Testing, ShouldBeTrue)
{
    std::string s1 = "adc";
    std::string s2 = "dcda";
    EXPECT_TRUE(Solution().checkInclusion(s1, s2));
}


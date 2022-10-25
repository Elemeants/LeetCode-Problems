#include "MaxLenght.h"
#include <gtest/gtest.h>

TEST(Testing, DefaultTest)
{
    Solution s;
    std::vector<std::string> expected = { "un", "iq", "ue" };
    EXPECT_EQ(s.maxLength(expected), 4);
}

TEST(Testing, DefaultUniqueCharacter)
{
    Solution s;
    std::vector<std::string> expected = { "cha", "r", "act", "ers" };
    EXPECT_EQ(s.maxLength(expected), 6);
}

TEST(Testing, DefaultABC)
{
    Solution s;
    std::vector<std::string> expected = { "abcdefghijklmnopqrstuvwxyz" };
    EXPECT_EQ(s.maxLength(expected), 26);
}

TEST(Testing, AllSubStringsAreRepeated)
{
    Solution s;
    std::vector<std::string> expected = { "aa", "bb" };
    EXPECT_EQ(s.maxLength(expected), 0);
}

TEST(Testing, TwoSubstringsWithRepeatedCharacters)
{
    Solution s;
    std::vector<std::string> expected = { "jnfbyktlrqumowxd","mvhgcpxnjzrdei" };
    EXPECT_EQ(s.maxLength(expected), 16);
}

TEST(Testing, TestConsecutivePathFind)
{
    Solution s;
    std::vector<std::string> expected = { "a", "abc", "d", "de", "def" };
    EXPECT_EQ(s.maxLength(expected), 6);
}

TEST(Testing, LastEntrySizeIsTheAnwser)
{
    Solution s;
    std::vector<std::string> expected = { "xdvqiefpcs", "vgnacw", "raobcnwgufztdykmsvlj" };
    EXPECT_EQ(s.maxLength(expected), 20);
}

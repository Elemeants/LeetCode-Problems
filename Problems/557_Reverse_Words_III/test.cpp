#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::string input    = "Let's take LeetCode contest";
    std::string expected = "s'teL ekat edoCteeL tsetnoc";
    EXPECT_EQ(Solution().reverseWords(input), expected);
}

TEST(Testing, DefaultTest2)
{
    std::string input    = "God Ding";
    std::string expected = "doG gniD";
    EXPECT_EQ(Solution().reverseWords(input), expected);
}

TEST(Testing, DefaultTest3)
{
    std::string input    = "I love u";
    std::string expected = "I evol u";
    EXPECT_EQ(Solution().reverseWords(input), expected);
}

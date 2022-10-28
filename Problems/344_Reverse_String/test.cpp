#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::vector<char> input    = {'h','e','l','l','o'};
    std::vector<char> expected = {'o','l','l','e','h'};
    Solution().reverseString(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, SingleChar)
{
    std::vector<char> input    = {'h'};
    std::vector<char> expected = {'h'};
    Solution().reverseString(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, DoubleChar)
{
    std::vector<char> input    = {'h','e'};
    std::vector<char> expected = {'e','h'};
    Solution().reverseString(input);
    EXPECT_EQ(input, expected);
}

TEST(Testing, ThreeChar)
{
    std::vector<char> input    = {'h','e','l'};
    std::vector<char> expected = {'l','e','h'};
    Solution().reverseString(input);
    EXPECT_EQ(input, expected);
}

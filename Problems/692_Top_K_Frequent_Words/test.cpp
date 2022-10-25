#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    std::vector<std::string> input = {"i", "love", "leetcode", "i", "love", "coding"};
    std::vector<std::string> expected = {"i", "love"};
    EXPECT_EQ(
        Solution().topKFrequent(input, 2),
        expected);
}

TEST(Testing, SecondDefaultTest)
{
    std::vector<std::string> input = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    std::vector<std::string> expected = {"the", "is", "sunny", "day"};
    EXPECT_EQ(
        Solution().topKFrequent(input, 4),
        expected);
}

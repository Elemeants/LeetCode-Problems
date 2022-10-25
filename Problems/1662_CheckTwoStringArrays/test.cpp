#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    Solution s;
    std::vector<std::string> r = {"ab", "c"};
    std::vector<std::string> r2 = {"a", "bc"};
    EXPECT_TRUE(s.arrayStringsAreEqual(r, r2));
}

TEST(Testing, DefaultUniqueCharacter)
{
    Solution s;
    std::vector<std::string> r = {"abc", "d", "defg"};
    std::vector<std::string> r2 = {"abcddefg"};
    EXPECT_TRUE(s.arrayStringsAreEqual(r, r2));
}

TEST(Testing, DefaultABC)
{
    Solution s;
    std::vector<std::string> r = {"a", "cb"};
    std::vector<std::string> r2 = {"ab", "c"};
    EXPECT_FALSE(s.arrayStringsAreEqual(r, r2));
}

TEST(Testing, a)
{
    Solution s;
    std::vector<std::string> r = {"jbboxe","yshcrtanrtlzyyp","vudsssnzuef","lde"};
    std::vector<std::string> r2 = {"jbboxeyshcrtanrt","lzyypvudsssnzueflde"};
    EXPECT_TRUE(s.arrayStringsAreEqual(r, r2));
}

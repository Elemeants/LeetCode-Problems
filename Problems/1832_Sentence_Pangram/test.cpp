#include <gtest/gtest.h>
#include "main.h"

TEST (Testing, DefaultTest)
{
    EXPECT_TRUE(Solution().checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));
}

TEST (Testing, SecondDefaultTest)
{
    EXPECT_FALSE(Solution().checkIfPangram("leetcode"));
}

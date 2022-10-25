#include <gtest/gtest.h>
#include "main.h"

TEST (Testing, DefaultTest)
{
    EXPECT_TRUE(Solution().containsNearbyDuplicate(std::vector<int>{1,2,3,1}, 3));
}

TEST (Testing, TestingDistance)
{
    EXPECT_TRUE(Solution().containsNearbyDuplicate(std::vector<int>{1,0,1,1}, 1));
}

TEST (Testing, RepetitivePattern)
{
    EXPECT_FALSE(Solution().containsNearbyDuplicate(std::vector<int>{1,2,3,1,2,3}, 2));
}

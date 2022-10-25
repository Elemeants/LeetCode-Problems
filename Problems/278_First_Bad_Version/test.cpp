#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.h"

bool isBadVersion(int version) {
    std::array<int, 6> a = {false, false, false, true, true, true};
    return a[version];
}

TEST(Testing, DefaultTest)
{
    EXPECT_EQ (Solution().firstBadVersion(5), 2);
}

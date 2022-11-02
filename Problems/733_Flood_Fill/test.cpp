#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    vector2D input = {
        { 1, 1, 1},
        { 1, 1, 0},
        { 1, 0, 1}
    };
    vector2D expected {
        { 2, 2, 2},
        { 2, 2, 0},
        { 2, 0, 1}
    };
    EXPECT_EQ(Solution().floodFill(input, 1, 1, 2), expected);
}

TEST(Testing, BasicCase)
{
    vector2D input = {
        { 0, 1, 0},
        { 1, 1, 1},
        { 0, 1, 0}
    };
    vector2D expected {
        { 0, 2, 0},
        { 2, 2, 2},
        { 0, 2, 0}
    };
    EXPECT_EQ(Solution().floodFill(input, 1, 1, 2), expected);
}

TEST(Testing, NoChanges)
{
    vector2D input = {
        { 0, 0, 0},
        { 0, 0, 0}
    };
    vector2D expected {
        { 0, 0, 0},
        { 0, 0, 0}
    };
    EXPECT_EQ(Solution().floodFill(input, 0, 0, 0), expected);
}

TEST(Testing, ChangeAllOfThem)
{
    vector2D input = {
        { 0, 0, 0},
        { 0, 0, 0}
    };
    vector2D expected {
        { 1, 1, 1},
        { 1, 1, 1}
    };
    EXPECT_EQ(Solution().floodFill(input, 0, 0, 1), expected);
}


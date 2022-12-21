#include <gtest/gtest.h>

#include "main.h"

TEST(Test841, Case1) {
  vector2D rooms = {{1}, {2}, {3}, {}};
  EXPECT_TRUE(Solution().canVisitAllRooms(rooms));
}

TEST(Test841, Case2) {
  vector2D rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
  EXPECT_FALSE(Solution().canVisitAllRooms(rooms));
}

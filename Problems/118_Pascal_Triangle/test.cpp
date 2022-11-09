#include <gtest/gtest.h>
#include "main.h"

TEST(Test118, Case1) {
  std::vector<std::vector<int>> triangle = {
    {1},
    {1, 1},
    {1, 2, 1},
    {1, 3, 3, 1},
    {1, 4, 6, 4, 1}
  };
  EXPECT_EQ(Solution().generate(5), triangle);
}

TEST(Test118, Case2) {
  std::vector<std::vector<int>> triangle = {
    {1}
  };
  EXPECT_EQ(Solution().generate(1), triangle);
}


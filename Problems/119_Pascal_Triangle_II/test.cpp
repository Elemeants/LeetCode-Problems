#include <gtest/gtest.h>
#include "main.h"

TEST(Test119, BaseCase) {
  std::vector<int> expected = {1};
  EXPECT_EQ(Solution().getRow(0), expected);
}

TEST(Test119, Case1) {
  std::vector<int> expected = {1, 2, 1};
  EXPECT_EQ(Solution().getRow(2), expected);
}

TEST(Test119, LargestCase) {
  std::vector<int> expected = {1, 32, 496, 4960, 35960, 201376, 906192, 3365856, 10518300, 28048800, 64512240, 129024480, 225792840, 347373600, 471435600, 565722720, 601080390, 565722720, 471435600, 347373600, 225792840, 129024480, 64512240, 28048800, 10518300, 3365856, 906192, 201376, 35960, 4960, 496, 32, 1};
  EXPECT_EQ(Solution().getRow(32), expected);
}


#include <gtest/gtest.h>
#include "main.h"

TEST(MockInterviewPietra, BaseCase) {
  const matrix2D baseCase = {
    { 0, 0 }
  };
  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(0, 0), std::make_pair(0, 1)), 1);
}

TEST(MockInterviewPietra, InterviewCase) {
  const matrix2D baseCase = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(0, 4), std::make_pair(4, 4)), 12);
}

TEST(MockInterviewPietra, InterviewSecondCase) {
  const matrix2D baseCase = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(0, 4), std::make_pair(3, 2)), -1);
}

TEST(MockInterviewPietra, InterviewCaseImposible) {
  const matrix2D baseCase = {
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(0, 4), std::make_pair(4, 4)), -1);
}

TEST(MockInterviewPietra, InterviewCaseImposible2) {
  const matrix2D baseCase = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(4, 0), std::make_pair(2, 2)), -1);
}

TEST(MockInterviewPietra, InterviewCaseImposible3) {
  const matrix2D baseCase = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(4, 0), std::make_pair(2, 2)), -1);
}

TEST(MockInterviewPietra, InterviewCaseImposibleLoop) {
  const matrix2D baseCase = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}
  };

  EXPECT_EQ(foundMinimalDistance(baseCase, std::make_pair(0, 4), std::make_pair(4, 4)), -1);
}

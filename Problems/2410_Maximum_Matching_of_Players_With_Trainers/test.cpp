#include <gtest/gtest.h>
#include "main.h"

TEST(Test2310, Example0) {
  std::vector<int> players = {4, 7 ,9};
  std::vector<int> trainers = {8, 2, 5, 8};
  EXPECT_EQ(Solution().matchPlayersAndTrainers(players, trainers), 2);
}

TEST(Test2310, Example1) {
  std::vector<int> players = {1, 1, 1};
  std::vector<int> trainers = {10};
  EXPECT_EQ(Solution().matchPlayersAndTrainers(players, trainers), 1);
}

TEST(Test2310, Case1) {
  std::vector<int> players = {1};
  std::vector<int> trainers = {1};
  EXPECT_EQ(Solution().matchPlayersAndTrainers(players, trainers), 1);
}

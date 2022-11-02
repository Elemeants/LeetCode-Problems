#include <gtest/gtest.h>
#include "main.h"

TEST (Test_CheckIfTwoStringsHaveOneMutationDifference, PositivePath) {
  const std::string start = "AACCGGTT";
  const std::string end   = "AACCGGTA";
  EXPECT_TRUE(Solution().isOneMutationValid(start, end));
}

TEST (Test_CheckIfTwoStringsHaveOneMutationDifference, NegativePath) {
  const std::string start = "AACCGGTT";
  const std::string end   = "AAACGGTA";
  EXPECT_FALSE(Solution().isOneMutationValid(start, end));
}

TEST (Testing, DefaultTest_1) {
  const std::string start = "AACCGGTT";
  const std::string end   = "AACCGGTA";
  const std::vector<std::string> bank = {
    "AACCGGTA"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, 1);
}

TEST (Testing, DefaultTest_2) {
  const std::string start = "AACCGGTT";
  const std::string end   = "AAACGGTA";
  const std::vector<std::string> bank = {
    "AACCGGTA","AACCGCTA","AAACGGTA"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, 2);
}

TEST (Testing, WithMultipleStartingPoints) {
  const std::string start = "AACCGGTT";
  const std::string end   = "AAACGGTA";
  const std::vector<std::string> bank = {
    "AACCGGTA","CACCGGTT","AAACGGTA"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, 2);
}

TEST (Testing, DefaultTest_3) {
  const std::string start = "AAAAACCC";
  const std::string end   = "AACCCCCC";
  const std::vector<std::string> bank = {
    "AAAACCCC","AAACCCCC","AACCCCCC"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, 3);
}

TEST (Testing, ReturnNoFound) {
  const std::string start = "AAAAACCC";
  const std::string end   = "TACCCCCC";
  const std::vector<std::string> bank = {
    "AAAACCCC","AAACCCCC","AACCCCCC"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, -1);
}

TEST (Testing, RecursiveExample) {
  const std::string start = "AAAACCCC";
  const std::string end   = "CCCCCCCC";
  const std::vector<std::string> bank = {
    "AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"
  };
  int steps = Solution().minMutation(start, end, bank);
  EXPECT_EQ(steps, 4);
}

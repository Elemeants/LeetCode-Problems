#include <gtest/gtest.h>

#include "main.h"

TEST(Test1233, Example1) {
  std::vector<std::string> folders = {
      "/a", "/a/b", "/c/d", "/c/d/e", "/c/f",
  };
  std::vector<std::string> expected = {
      "/a",
      "/c/d",
      "/c/f",
  };
  EXPECT_EQ(expected, Solution().removeSubfolders(folders));
}

TEST(Test1233, Example2) {
  std::vector<std::string> folders = {"/a", "/a/b/c", "/a/b/d"};
  std::vector<std::string> expected = {"/a"};
  EXPECT_EQ(expected, Solution().removeSubfolders(folders));
}

TEST(Test1233, Example3) {
  std::vector<std::string> folders = {"/a/b/c", "/a/b/ca", "/a/b/d"};
  std::vector<std::string> expected = {"/a/b/c", "/a/b/ca", "/a/b/d"};
  EXPECT_EQ(expected, Solution().removeSubfolders(folders));
}

TEST(Test1233, Case0) {
  std::vector<std::string> folders = {"/helloworldfolder", "/a/b/ca"};
  std::vector<std::string> expected = {"/helloworldfolder", "/a/b/ca"};
  EXPECT_EQ(expected, Solution().removeSubfolders(folders));
}

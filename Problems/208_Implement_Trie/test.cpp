#include <gtest/gtest.h>
#include "main.h"

TEST(Test208, Case1)
{
  Trie* obj = new Trie();
  obj->insert("apple");
  EXPECT_TRUE(obj->search("apple"));
  EXPECT_FALSE(obj->search("app"));
  EXPECT_TRUE(obj->startsWith("app"));
  obj->insert("app");
  EXPECT_TRUE(obj->search("app"));
  delete obj;
}

TEST(Test208, Case2)
{
  Trie* obj = new Trie();
  obj->insert("hello");
  EXPECT_FALSE(obj->search("hell"));
  EXPECT_FALSE(obj->search("helloa"));
  EXPECT_TRUE(obj->search("hello"));
  EXPECT_TRUE(obj->startsWith("hell"));
  EXPECT_FALSE(obj->startsWith("helloa"));
  EXPECT_TRUE(obj->startsWith("hello"));
  delete obj;
}

//
// 208. Implement Trie (Prefix Tree)
//
#pragma once

#include <string>
#include <map>
#include <unordered_map>

class Trie
{
  struct TreeNode
  {
    TreeNode() : val(0), word("") {}
    TreeNode(char x) : val(x), word("") {}
    TreeNode(char x, std::string word) : val(x), word(word) {}

    char val;
    std::string word;
    std::map<char, TreeNode *> childs;
  };
  TreeNode root;

public:
  Trie() : root() {}

  void insert(std::string word)
  {
    TreeNode *_node = &root;
    for (const char c : word)
    {
      if (_node->childs.count(c) == 0)
      {
        TreeNode *new_child = new TreeNode(c);
        _node->childs[c] = new_child;
      }
      _node = _node->childs[c];
    }
    _node->word = word;
  }

  bool search(std::string word)
  {
    TreeNode *_node = &root;
    for (const char c : word)
    {
      if (_node->childs.count(c) == 0)
      {
        return false;
      }
      _node = _node->childs[c];
    }
    return _node->word == word;
  }

  bool startsWith(std::string prefix)
  {
    TreeNode *_node = &root;
    for (const char c : prefix)
    {
      if (_node->childs.count(c) == 0)
      {
        return false;
      }
      else
      {
        _node = _node->childs[c];
      }
    }
    return true;
  }

  void printInternalTree()
  {
    __printTree(&root, 0);
  }

  void __printTree(const TreeNode *_node, int level)
  {
    for (int i = 0; i < level; i++)
    {
      std::cout << " ";
    }
    std::cout << _node->val << std::endl;
    for (const auto &node : _node->childs)
    {
      __printTree(node.second, level + 1);
    }
  }
};

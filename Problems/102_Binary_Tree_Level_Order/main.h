//
// 102. Binary Tree Level Order Traversal
//
#pragma once

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <deque>
#include <iostream>

using vector2D = std::vector<std::vector<int>>;

class Solution
{
public:
  // Transform from tree node to values per level
  vector2D levelOrder(TreeNode *root)
  {
    vector2D result;
    if (root == nullptr) { return result; }

    std::deque<std::pair<TreeNode*, int>> nodes;
    nodes.push_front(std::make_pair(root, 0));
    result.push_back({root->val});

    std::vector<int> level_nodes;

    int level_index = 1;
    while (nodes.size() > 0) {
      auto node = nodes.front(); nodes.pop_front();

      if (node.second > level_index) {
        level_index = node.second;
        result.push_back(level_nodes);
        level_nodes.clear();
      }

      if (node.second > 0) {
        level_nodes.push_back(node.first->val);
      }

      if (node.first->left != nullptr) {
        nodes.push_back(std::make_pair(node.first->left, node.second + 1));
      }
      if (node.first->right != nullptr) {
        nodes.push_back(std::make_pair(node.first->right, node.second + 1));
      }
    }

    if (level_nodes.size() > 0) {
      result.push_back(level_nodes);
    }

    return result;
  }
};

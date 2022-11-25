//
// 572. Subtree of Another Tree
//
#pragma once

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <deque>

class Solution {
 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    std::deque<TreeNode*> nodes;
    nodes.push_back(root);
    bool founded = false;

    while (nodes.size() > 0) {
      auto node = nodes.back(); nodes.pop_back();

      if (node->val == subRoot->val) {
        if (checkIfBothTreesAreEqual(node, subRoot)) {
          founded = true;
          break;
        }
      }

      if (node->left != nullptr) {
        nodes.push_front(node->left);
      }
      if (node->right != nullptr) {
        nodes.push_front(node->right);
      }
    }

    return founded;
  }

  bool checkIfBothTreesAreEqual(TreeNode *root, TreeNode *subRoot) {
    if (!subRoot && !root) {
      return true;
    }

    if (!subRoot || !root) {
      return false;
    }

    if (!checkIfBothTreesAreEqual(root->left, subRoot->left)) {
      return false;
    }

    if (!checkIfBothTreesAreEqual(root->right, subRoot->right)) {
      return false;
    }

    return root->val == subRoot->val;
  }
};

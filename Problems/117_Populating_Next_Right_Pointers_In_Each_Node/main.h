//
// 117. Populating Next Right Pointers in Each Node II
//
#pragma once

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

#include <deque>
#include <iostream>

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root)
      return root;

    std::deque<std::pair<Node*, int>> nodes;
    Node* prevNode = root;
    nodes.push_back(std::make_pair(root, 0));
    int lastLevel = -1;

    while (nodes.size() > 0) {
      auto node = nodes.back(); nodes.pop_back();
      node.first->next = NULL;
      prevNode->next = node.first;

      if (node.second != lastLevel) {
        prevNode->next = NULL;
        lastLevel = node.second;
      }

      if (node.first->left) {
        nodes.push_front(std::make_pair(node.first->left, node.second + 1));
      }
      if (node.first->right) {
        nodes.push_front(std::make_pair(node.first->right, node.second + 1));
      }

      prevNode = node.first;
    }

    return root;
  }
};

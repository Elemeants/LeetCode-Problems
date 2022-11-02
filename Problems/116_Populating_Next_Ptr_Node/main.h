//
// 116. Populating Next Right Pointers in Each Node
//
#pragma once

#include <iostream>
#include <unordered_set>
#include <deque>
#include <queue>

class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root) {
      return root;
    }

    std::queue<
        std::pair<Node*, int>,
        std::deque<std::pair<Node*, int>>>
        queue;
    queue.push(std::make_pair(root, 0));
    std::pair<Node*, int> prevNode = queue.front();

    while (queue.size() > 0)
    {
      const auto i = queue.front();
      queue.pop();

      if (prevNode.second < i.second) {
        prevNode.first->next = nullptr;
      } else {
        prevNode.first->next = i.first;
      }

      if (i.first->left) {
        queue.push(std::make_pair(i.first->left, i.second + 1));
      }

      if (i.first->right) {
        queue.push(std::make_pair(i.first->right, i.second + 1));
      }

      prevNode = i;
    }

    prevNode.first->next = nullptr;

    return root;
  }
};
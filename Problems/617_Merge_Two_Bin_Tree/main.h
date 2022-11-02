//
// 617. Merge Two Bin Tree
//
#pragma once

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        if (root1 == nullptr)
        {
            return root2;
        }
        if (root2 == nullptr)
        {
            return root1;
        }

        TreeNode *newRoot = new TreeNode(root1->val + root2->val);

        newRoot->left = mergeTrees(
            root1 ? root1->left : nullptr,
            root2 ? root2->left : nullptr);
        newRoot->right = mergeTrees(
            root1 ? root1->right : nullptr,
            root2 ? root2->right : nullptr);

        return newRoot;
    }
};
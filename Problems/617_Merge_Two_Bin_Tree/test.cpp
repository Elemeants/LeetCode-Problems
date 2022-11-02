#include <gtest/gtest.h>
#include "main.h"

TEST(Test617, BaseCaseNoBranches)
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *expected = new TreeNode(3);

    TreeNode *rslt = Solution().mergeTrees(root1, root2);

    EXPECT_EQ(rslt->val, expected->val);
}

TEST(Test617, BaseCaseBothBranches)
{
    TreeNode *root1_0 = new TreeNode(2);
    TreeNode *root1_1 = new TreeNode(2);
    TreeNode *root1 = new TreeNode(1, root1_0, root1_1);
    TreeNode *root2_0 = new TreeNode(2);
    TreeNode *root2_1 = new TreeNode(2);
    TreeNode *root2 = new TreeNode(2, root2_0, root2_1);

    TreeNode *expected_0 = new TreeNode(4);
    TreeNode *expected_1 = new TreeNode(4);
    TreeNode *expected = new TreeNode(3, expected_0, expected_1);

    TreeNode *rslt = Solution().mergeTrees(root1, root2);

    EXPECT_EQ(rslt->val, expected->val);
    EXPECT_EQ(rslt->left->val, expected->left->val);
    EXPECT_EQ(rslt->right->val, expected->right->val);
}

TEST(Test617, BaseCaseOnlyDifferentBranches)
{
    TreeNode *root1_1 = new TreeNode(2);
    TreeNode *root1 = new TreeNode(1, nullptr, root1_1);
    TreeNode *root2_0 = new TreeNode(2);
    TreeNode *root2 = new TreeNode(2, root2_0, nullptr);

    TreeNode *expected_0 = new TreeNode(2);
    TreeNode *expected_1 = new TreeNode(2);
    TreeNode *expected = new TreeNode(3, expected_0, expected_1);

    TreeNode *rslt = Solution().mergeTrees(root1, root2);

    EXPECT_EQ(rslt->val, expected->val);
    EXPECT_EQ(rslt->left->val, expected->left->val);
    EXPECT_EQ(rslt->right->val, expected->right->val);
}

TEST(Test617, DefaultTest)
{
    TreeNode *root1_0_0 = new TreeNode(5);
    TreeNode *root1_0 = new TreeNode(3, root1_0_0, nullptr);
    TreeNode *root1_1 = new TreeNode(2);
    TreeNode *root1 = new TreeNode(1, root1_0, root1_1);

    TreeNode *root2_0_1 = new TreeNode(4);
    TreeNode *root2_0 = new TreeNode(1, nullptr, root2_0_1);
    TreeNode *root2_1_1 = new TreeNode(7);
    TreeNode *root2_1 = new TreeNode(3, nullptr, root2_1_1);
    TreeNode *root2 = new TreeNode(2, root2_0, root2_1);

    TreeNode *expected_0_0 = new TreeNode(5);
    TreeNode *expected_0_1 = new TreeNode(4);
    TreeNode *expected_0 = new TreeNode(4, expected_0_0, expected_0_1);
    TreeNode *expected_1_1 = new TreeNode(7);
    TreeNode *expected_1 = new TreeNode(5, nullptr, expected_1_1);
    TreeNode *expected = new TreeNode(3, expected_0, expected_1);

    TreeNode *rslt = Solution().mergeTrees(root1, root2);

    EXPECT_EQ(rslt->val, expected->val);
    EXPECT_EQ(rslt->left->val, expected->left->val);
    EXPECT_EQ(rslt->left->left->val, expected->left->left->val);
    EXPECT_EQ(rslt->left->right->val, expected->left->right->val);
    EXPECT_EQ(rslt->right->val, expected->right->val);
    EXPECT_EQ(rslt->right->right->val, expected->right->right->val);
}

#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, DefaultTest)
{
    ListNode* node_4 = new ListNode(4);
    ListNode* node_3 = new ListNode(3, node_4);
    ListNode* node_2 = new ListNode(2, node_3);
    ListNode* node_1 = new ListNode(1, node_2);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().middleNode(node_0), node_2);
}

TEST(Testing, OneNode)
{
    ListNode* node_0 = new ListNode(0);
    
    EXPECT_EQ(Solution().middleNode(node_0), node_0);
}

TEST(Testing, TwoNode)
{
    ListNode* node_1 = new ListNode(1);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().middleNode(node_0), node_1);
}

TEST(Testing, ThreeNode)
{
    ListNode* node_2 = new ListNode(2);
    ListNode* node_1 = new ListNode(1, node_2);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().middleNode(node_0), node_1);
}

TEST(Testing, FourNode)
{
    ListNode* node_3 = new ListNode(3);
    ListNode* node_2 = new ListNode(2, node_3);
    ListNode* node_1 = new ListNode(1, node_2);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().middleNode(node_0), node_2);
}

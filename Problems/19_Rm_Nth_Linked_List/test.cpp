#include <gtest/gtest.h>
#include "main.h"

TEST(Testing, OneNode)
{
    ListNode* node_0 = new ListNode(0);
    ListNode* result = Solution().removeNthFromEnd(node_0, 1);
    
    EXPECT_EQ(result, nullptr);
}

TEST(Testing, TwoNode)
{
    ListNode* node_1 = new ListNode(1);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().removeNthFromEnd(node_0, 2), node_1);
    delete node_1;
}

TEST(Testing, TwoNodeRemoveLast)
{
    ListNode* node_1 = new ListNode(1);
    ListNode* node_0 = new ListNode(0, node_1);
    
    EXPECT_EQ(Solution().removeNthFromEnd(node_0, 1), node_0);
    delete node_0;
}

TEST(Testing, ThreeNode)
{
    ListNode* node_2 = new ListNode(1);
    ListNode* node_1 = new ListNode(1, node_2);
    ListNode* node_0 = new ListNode(0, node_1);
    
    ListNode* r = Solution().removeNthFromEnd(node_0, 3);
    EXPECT_EQ(r, node_1);
    r = r->next;
    EXPECT_EQ(r, node_2);
    delete node_1;
    delete node_2;
}

TEST(Testing, ThreeNodeRemoveMiddle)
{
    ListNode* node_2 = new ListNode(1);
    ListNode* node_1 = new ListNode(1, node_2);
    ListNode* node_0 = new ListNode(0, node_1);

    ListNode* r = Solution().removeNthFromEnd(node_0, 2);
    EXPECT_EQ(r, node_0);
    r = r->next;
    EXPECT_EQ(r, node_2);
    delete node_0;
    delete node_2;
}

//
// 82. Remove Duplicates from Sorted List II
//
#pragma once

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *startNode)
  {
    ListNode* head = startNode;
    if (!head || !head->next) {
      return head;
    }
    ListNode* result = NULL;
    ListNode* result_head = NULL;

    int lastValue = head->val;
    bool wasDuplicated = false;
    head = head->next;

    while (head) {
      if (head->val != lastValue) {
        if (!wasDuplicated) {
          if (!result) {
            result = new ListNode(lastValue);
            result_head = result;
          } else {
            result_head->next = new ListNode(lastValue);
            result_head = result_head->next;
          }
        }
        wasDuplicated = false;
      } else if (head->val == lastValue) {
        wasDuplicated = true;
      }

      lastValue = head->val;
      head = head->next;
    }

    if (!wasDuplicated) {
      if (!result) {
        result = new ListNode(lastValue);
        result_head = result;
      } else {
        result_head->next = new ListNode(lastValue);
        result_head = result_head->next;
      }
    }

    return result;
  }
};

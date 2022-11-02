//
// 21. Merge Two Sorted Lists
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == nullptr && list2 == nullptr) {
      return nullptr;
    }

    ListNode *head = new ListNode();
    ListNode *tail = head;
    bool finished = false;

    while (!finished)
    {
      if (list1 == nullptr) {
        tail->val = list2->val;
        list2 = list2->next;
      } else if (list2 == nullptr) {
        tail->val = list1->val;
        list1 = list1->next;
      } else if (list1->val < list2->val) {
        tail->val = list1->val;
        list1 = list1->next;
      } else {
        tail->val = list2->val;
        list2 = list2->next;
      }

      if (list1 == nullptr && list2 == nullptr) {
        break;
      }

      tail->next = new ListNode();
      tail = tail->next;
    }

    return head;
  }
};
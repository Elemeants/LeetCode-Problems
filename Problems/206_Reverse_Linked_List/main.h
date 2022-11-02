//
// 206. Reverse Linked List
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) { return head; }

        ListNode* new_tail = new ListNode(head->val);
        ListNode* new_head = nullptr;
        head = head->next;

        while (head != nullptr) {
            new_head = new ListNode(head->val);
            new_head->next = new_tail;

            head = head->next;
            new_tail = new_head;
        }

        return new_head;
    }
};
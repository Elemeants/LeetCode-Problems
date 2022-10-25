//
// 2. Add Two Numbers
//
#pragma once

#include <algorithm>
#include <numeric>
#include <stdint.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool countOneMoreNext = false;
        ListNode* newList = new ListNode();
        ListNode* pList = newList;
        ListNode* pL1 = l1;
        ListNode* pL2 = l2;

        while (true) {
            pList->val = (pL1 ? pL1->val : 0) + (pL2 ? pL2->val : 0) + (countOneMoreNext ? 1 : 0);
            
            if (countOneMoreNext) {
                countOneMoreNext = false;
            }

            if (pList->val >= 10) {
                pList->val -= 10;
                countOneMoreNext = true;
            }

            pL1 = pL1 ? pL1->next : NULL;
            pL2 = pL2 ? pL2->next : NULL;

            if (pL1 == NULL && pL2 == NULL && countOneMoreNext == 0) {
                break;
            }

            pList->next = new ListNode();
            pList = pList->next;
        }
        
        return newList;
    }
};

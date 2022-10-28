//
// 876. Middle of the Linked List
//
#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *c = head;
        ListNode *m = head;
        int count = 0;
        while (c != nullptr) {
            c = c->next;
            count ++;
            if (count == 2) {
                m = m->next;
                count = 0;
            }
        }
        return m;
    }
};

//
// 19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *_rm_node = head;
        ListNode *_tail = head;

        int list_lenght = 0;
        int index_to_remove = 0;
        while (_tail) {
            _tail = _tail->next;
            list_lenght ++;
            if (list_lenght > (n + 1)) {
                index_to_remove ++;
                _rm_node = _rm_node->next;
            }
        }

        if (list_lenght == 1) {
            return NULL;
        }

        if (_rm_node) {
            const int diff = abs(list_lenght - n);
            if (_rm_node == head && diff == 0) {
                ListNode *r = head;
                head = head->next;
                delete r;
            } else {
                ListNode *r = _rm_node->next;
                _rm_node->next = _rm_node->next->next;
                delete r;
            }
        }

        return head;
    }
};
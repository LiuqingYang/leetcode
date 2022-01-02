// https://leetcode.com/problems/middle-of-the-linked-list/

#include "header.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        while (head->next) {
            mid = mid->next;
            head = head->next;
            if (head->next) {
                head = head->next;
            }
        }
        return mid;
    }
};

// https://leetcode.com/problems/rotate-list/

#include "header.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        
        int len = 1;
        ListNode* tmp = head;
        
        while(tmp->next) {
            len++;
            tmp = tmp->next;
        }
        tmp->next = head;
        
        len -= k % len;
        while (--len) {
            head = head->next;
        }
        tmp = head->next;
        head->next = nullptr;
        
        return tmp;
    }
};
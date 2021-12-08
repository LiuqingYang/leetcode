// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        
        while(head) {
            ret = ret * 2 + head->val;
            head = head->next;
        }
        
        return ret;
    }
};
#include "header.h"

/* use helper to replace head can minimize code and speed up */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode helper(0);
        
        ListNode *curr = head;
        ListNode *prev = &helper;
        helper.next = head;
        
        while (curr && curr->next) {
            ListNode *node1 = curr;
            ListNode *node2 = curr->next;

            prev->next = node2;
            
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
            curr = node1->next;
        }
        
        return helper.next;
    }
};


/* a quicker one using C

struct ListNode* swapPairs(struct ListNode* head) {
        struct ListNode *curr = head;
        struct ListNode *prev = NULL;
        struct ListNode *n1 = curr;
        struct ListNode *n2;
        
        if (n1 == NULL) return head;
        n2 = n1->next;
        if (n2 == NULL) return head;
        
        head = n2;
        n1->next = n2->next;
        n2->next = n1;
        prev = n1;
        curr = n1->next;
        
        while (curr) {
            struct ListNode *node1;
            struct ListNode *node2;
            
            node1 = curr;
            node2 = curr->next;
            
            if (node2 == NULL) break;
            
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            prev = node1;
            curr = node1->next;
        }
        
        return head;
    
}

*/

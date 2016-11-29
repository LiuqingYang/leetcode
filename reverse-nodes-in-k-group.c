#include "header.h"

/* Try many times to pass, write enough draft may simplify it */
/* use helper to minimize code, see swap-nodes-in-pairs.cpp, not imple here */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *prev_reverse = NULL;
    struct ListNode *start = head;
    int i;
    
    if (head == NULL || k == 1) return head;
    
    for (i = 0; i < k; i++) {
        curr = curr->next;
        if (curr == NULL && i != (k - 1)) return head;
    }
    
    /* reverse from start to curr*/
    while (start->next != curr) {
        struct ListNode *next_node = start->next;
        start->next = prev_reverse;
        prev_reverse = start;
        start = next_node;
    }
    head->next = curr;
    start->next = prev_reverse;
    prev = head;
    head = start;
    
    while (curr) {
        struct ListNode *inner_start = curr;
        struct ListNode *inner_prev = prev->next;
        struct ListNode *inner_prev_reverse = prev;
        
        for (i = 0; i < k; i++) {
            curr = curr->next;
            if (curr == NULL && i != (k - 1)) return head;
        }
        
        while(inner_start->next != curr) {
            struct ListNode *next_node = inner_start->next;
            inner_start->next = inner_prev_reverse;
            inner_prev_reverse = inner_start;
            inner_start = next_node;
        }
        inner_prev->next = curr;
        inner_start->next = inner_prev_reverse;
        prev->next = inner_start;
        prev = inner_prev;
    }
    
    return head;
}

int main()
{
    struct ListNode n1, n2, n3, n4;
    struct ListNode *ret;
    
    n1.val = 1;
    n1.next = &n2;
    n2.val = 2;
    n2.next = &n3;
    n3.val = 3;
    n3.next = &n4;
    n4.val = 4;
    n4.next = NULL;
    
    ret = reverseKGroup(&n1, 2);
}

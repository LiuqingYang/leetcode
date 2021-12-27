// https://leetcode.com/problems/reorder-list/

#include "header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode* tail = head;
        ListNode* mid = head;
        
        while(tail->next) {
            if (size++ % 2) {
                mid = mid->next;
            }
            tail = tail->next;
        }
        
        ListNode* midnext = mid->next;
        if (!midnext) {
            return;
        }
        while(midnext->next) {
            ListNode* tmp = midnext->next;
            midnext->next = mid;
            mid = midnext;
            midnext = tmp;
        }
        midnext->next = mid;
        
        while(1) {
            ListNode* tmp = head->next;
            head->next = tail;
            ListNode* tmp2 = tail->next;
            tail->next = tmp;
            if (tmp == tmp2) {
                tmp->next = nullptr;
                break;
            } else if (tmp->next == tmp2) {
                tmp->next->next = nullptr;
                break;
            }
            head = tmp;
            tail = tmp2;
        }
    }
};

int main() {
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode* p = &n1;

    Solution sol;
    sol.reorderList(p);
}

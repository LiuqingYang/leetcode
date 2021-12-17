// https://leetcode.com/problems/insertion-sort-list/

#include "header.h"

// 直接使用node->next->val进行判断，可减少一个指针的使用

// 看其他人答案获得的两个优化：
// 对于head可变的链表处理，使用dummy node指向head，可以避免head处理逻辑
// 对于无需插入的情况，即node->val > node->next->val，直接处理下一个节点可加快运行速度

// 链表本身是个低效的结构，所以构造vector然后排序甚至更快（可以使用快速排序）
// 少数情况下可能不得不使用链表

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* node = head;
        
        while (node->next != nullptr) {
            if (node->val > node->next->val) {
                ListNode* insert = &dummy;
                while (insert != node) {
                    if (node->next->val <= insert->next->val) {
                        ListNode* newInsert = node->next;
                        node->next = node->next->next;
                        newInsert->next = insert->next;
                        insert->next = newInsert;
                        break;
                    }
                    insert = insert->next;
                }
            } else {
                node = node->next;
            }            
        }
        
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode d(3);
    ListNode c(1, &d);
    ListNode b(2, &c);
    ListNode a(4, &b);

    sol.insertionSortList(&a);
}
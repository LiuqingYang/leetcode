// https://leetcode.com/problems/add-two-numbers/
// Yang Liuqing
// yllqq@outlook.com


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *ret = NULL;
            ListNode *curr = NULL;
            int carry = 0;

            while (l1 || l2)
            {
                int sum = carry;
                ListNode *node;

                if (l1)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }

                node = new ListNode(sum % 10);
                if (ret)
                {
                    curr->next = node;
                    curr = curr->next;
                }
                else
                {
                    ret = node;
                    curr = node;
                }

                carry = sum / 10;
            }

            if (carry)
            {
                if (ret)
                {
                    curr->next = new ListNode(carry);
                    curr = curr->next;
                }
                else
                {
                    ret = new ListNode(carry);
                }
            }

            return ret;

    }
};

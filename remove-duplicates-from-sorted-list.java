/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode last = head;
        int last_val = head.val;
        ListNode curr = head.next;
        
        while (curr != NULL) {
            if (last_val == curr.val) {
                last.next = curr.next;
                curr = curr.next;
            } else {
                last_val = curr.val;
                last = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}

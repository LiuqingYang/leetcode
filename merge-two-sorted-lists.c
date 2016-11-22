#include "header.h"

// use online testcase now

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *ret = NULL;
  struct ListNode *head = NULL;
  
  while (l1 || l2) {
    struct ListNode *next = NULL;
    if (!l2) {
      next = l1;
      l1 = l1->next;
    } else if (!l1) {
      next = l2;
      l2 = l2->next;
    } else if (l1->val <= l2->val) {
      next = l1;
      l1 = l1->next;
    } else {
      next = l2;
      l2 = l2->next;
    }
    
    if (!ret) {
      ret = next;
      head = next;
    } else {
      head->next = next;
      head = next;
    }
  }
  
  if (head) {
    head->next = NULL;
  }
  return ret;
}

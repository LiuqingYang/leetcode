// https://leetcode.com/problems/integer-to-roman/
// Yang Liuqing
// yllqq@outlook.com

// possible to change the head

#include "header.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode *ret = head;
  struct ListNode *head_minus_n = head;
  struct ListNode *tmp;

  if (head == NULL || n == 0) return head;

  while (n) {
    if (head) {
      head = head->next;
      n--;
    } else {
      return ret;
    }
  }

  if (head == NULL) {
    /* remove original head */
    ret = ret->next;
    free(head_minus_n);
    return ret;
  }

  while(head->next) {
    head = head->next;
    head_minus_n = head_minus_n->next;
  }

  tmp = head_minus_n->next;
  head_minus_n->next = tmp->next;
  free(tmp);

  return ret;
}

int main() {
  struct ListNode *nodes[5];
  struct ListNode *single;
  struct ListNode *ret;
  int i;

  nodes[4] = malloc(sizeof(struct ListNode));
  nodes[4]->val = 5;
  nodes[4]->next = NULL;

  for (i = 3; i >= 0; i--) {
    nodes[i] = malloc(sizeof(struct ListNode));
    nodes[i]->val = i + 1;
    nodes[i]->next = nodes[i+1];
  }

  removeNthFromEnd(nodes[0], 2);

  single = malloc(sizeof(struct ListNode));
  single->val = 1;
  single->next = NULL;
  ret = removeNthFromEnd(single, 1);
  printf("%p\n", ret);
}

#include "header.h"

class Solution {
private:
  struct comparator {
   bool operator()(ListNode *i, ListNode *j) {
   return i->val > j->val;
   }
  };
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ret = NULL;
    ListNode *curr = NULL;
    priority_queue<ListNode*, std::deque<ListNode *>, comparator> minHeap;
    
    for (ListNode *ele : lists) {
      if (ele != NULL) minHeap.push(ele);
    }
    
    if (minHeap.empty()) {
      return ret;
    } else {
      ret = minHeap.top();
      curr = ret;
      minHeap.pop();
      if (ret->next) minHeap.push(ret->next);
    }
    
    while (!minHeap.empty()) {
      ListNode *ele = minHeap.top();
      minHeap.pop();
      curr->next = ele;
      curr = ele;
      if (curr->next) minHeap.push(curr->next);
    }
    
    return ret;
  }
};

int main() {
  ListNode l1(0);
  ListNode l2(2);
  ListNode l3(5);
  vector<ListNode *> lists;
  Solution sol;
  ListNode *ret;
  
  l1.next = &l2;
  l2.next = &l3;
  lists.push_back(&l1);
  
  ret = sol.mergeKLists(lists);
  return 0;
}

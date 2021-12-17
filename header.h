#ifdef __cplusplus
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <bitset>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#else /* C */

struct ListNode {
   int val;
   struct ListNode *next;
};

#endif /* __cplusplus */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

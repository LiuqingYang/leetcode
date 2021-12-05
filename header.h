#ifdef __cplusplus
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
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


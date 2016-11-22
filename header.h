#ifdef __cplusplus
#include <vector>
#include <string>
#include <iostream>

using namespace std;

* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };

#else /* C */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

#endif /* __cplusplus */

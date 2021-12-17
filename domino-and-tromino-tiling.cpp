// https://leetcode.com/problems/domino-and-tromino-tiling/

#include "header.h"

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        unsigned int mod = 1e9 + 7;
        
        unsigned int a1 = 1;
        unsigned int a2 = 1;
        unsigned int b1 = 2;
        
        int loop_count = n - 2;
        while (loop_count--) {
            int b2 = (a1 + a2) % mod;
            int c1 = (a1 + 2 * a2 + b1) % mod;
            a1 = b1;
            a2 = b2;
            b1 = c1;
        }
        return b1;
    }
};

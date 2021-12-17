// https://leetcode.com/problems/nth-magical-number/

#include "header.h"

// 另可使用二分查找法，因为对于给定数可以知道位于第几位
// 似乎使用两者结合能够更快，即在while内使用二分查找
// 对于成绩提升没有帮助，不再尝试

class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        unsigned int m = 1e9 + 7;
        
        int max = a / gcd(a, b) * b;        
        int count = max / a + max / b - 1;
        int delta = n % count;
        unsigned int base = (((int64_t)n / count) * max) % m;
        if (delta == 0) return base;

        int current_a = a;
        int current_b = b;
        while (1) {
            delta--;
            if (current_a < current_b) {
                if (delta == 0) return (base + current_a) % m;
                current_a += a;
            } else {
                if (delta == 0) return (base + current_b) % m;
                current_b += b;
            }
        }
    }
};
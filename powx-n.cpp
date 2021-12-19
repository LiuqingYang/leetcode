// https://leetcode.com/problems/powx-n/

#include "header.h"

// 点踩太多，但此方法能够log(n)解决，算是比较标准的递归下降

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT_MIN) {
                return 1 / myPow(x, INT_MAX) / x;
            } else {
                return 1 / myPow(x, -n);
            }
        } else if (n == 0) {
            return x == 0.0 ? 0.0 : 1.0;
        } else if (n == 1) {
            return x;
        } else if ((n % 2) == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x * x, (n - 1) / 2);
        }
    }
};


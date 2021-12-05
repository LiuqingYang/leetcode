// https://leetcode.com/problems/divide-two-integers/

#include "header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int64_t ret = (int64_t)dividend / divisor;
        if (ret > INT_MAX) return INT_MAX;
        else if (ret < INT_MIN) return INT_MIN;
        else return int(ret);
    }
};

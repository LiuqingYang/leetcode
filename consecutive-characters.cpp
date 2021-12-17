// https://leetcode.com/problems/consecutive-characters/

#include "header.h"

class Solution {
public:
    int maxPower(string s) {
        char now = 0;
        int ret = 0;
        int len = 0;
        int count = s.size();
        for (int i = 0; i < count; i++) {
            char c = s[i];
            if (c == now) {
                ++len;
            } else {
                ret = max(ret, len);
                now = c;
                len = 1;
            }
        }
        ret = max(ret, len);
        return ret;
    }
};

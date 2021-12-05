// https://leetcode.com/problems/count-and-say/

#include "header.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string last = countAndSay(n - 1);
        string s;
        char lastch = 0;
        int count = 0;
        char buf[255];
        
        for(char ch : last) {
            if (ch != lastch) {
                if (count != 0) {
                    s += to_string(count);
                    s += lastch;
                }
                lastch = ch;
                count = 1;
            } else {
                count++;
            }
        }
        
        s += to_string(count);
        s += lastch;
        return s;
    }
};
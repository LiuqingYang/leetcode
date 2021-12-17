// https://leetcode.com/problems/length-of-last-word/

#include "header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        auto it = s.rbegin();
        while (it != s.rend() && *it == ' ') {
            ++it;
        }
        while (it != s.rend() && *it != ' ') {
            ++it;
            ++length;
        }
        return length;
    }
};

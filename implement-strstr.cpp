// https://leetcode.com/problems/implement-strstr/

#include "header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_count = needle.size();
        if (needle_count == 0) return 0;
        
        int loop = haystack.size() - needle_count;
        for (int i = 0; i <= loop; i++) {
            if (memcmp(haystack.data() + i, needle.data(), needle_count) == 0) {
                return i;
            }
        }
        return -1;
    }
};
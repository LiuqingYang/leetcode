// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include "header.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int modCount[60] = {0};
        int ret = 0;
        for (int t : time) {
            ret += modCount[(60 - t % 60) % 60];
            modCount[t % 60]++;
        }
                
        return ret;
    }
};

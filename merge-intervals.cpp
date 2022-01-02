// https://leetcode.com/problems/merge-intervals/

#include "header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& v1, const vector<int>& v2) {return v1[0] < v2[0];});
        
        int lower = -1;
        int upper = -1;
        int count = intervals.size();
        vector<vector<int>> ret;
        for (int i = 0; i < count; i++) {
            vector<int>& curr = intervals[i];
            if (lower == -1) {
                lower = curr[0];
                upper = curr[1];
            } else if (curr[0] > upper) {
                ret.push_back({lower, upper});
                lower = curr[0];
                upper = curr[1];
            } else {
                upper = max(curr[1], upper);
            }
        }
        if (lower != -1) {
            ret.push_back({lower, upper});
        }
        return ret;
    }
};

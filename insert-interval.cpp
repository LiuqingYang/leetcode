// https://leetcode.com/problems/insert-interval/

#include "header.h"

// 可以通过分3段来简化流程：<newInterval 位于newInterval >newInterval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        if (intervals.size() == 0 || intervals[0][0] > newInterval[1]) {
            ret.push_back({newInterval});
        }
        int lower = -1;
        int upper = -1;
        int last_upper = -1;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& curr = intervals[i];
            if (curr[1] < newInterval[0] || curr[0] > newInterval[1]) {
                if (lower != -1) {
                    ret.push_back({lower, upper});
                    lower = -1;
                    last_upper = upper;
                }
                if (last_upper != -1 && newInterval[0] > last_upper && newInterval[1] < curr[0]) {
                    ret.push_back({newInterval});
                    last_upper = newInterval[1];
                }
                ret.push_back(curr);
                last_upper = curr[1];
            } else if (lower == -1) {
                lower = min(curr[0], newInterval[0]);
                upper = max(curr[1], newInterval[1]);
            } else {
                upper = max(upper, curr[1]);
            }
        }
        if (lower != -1) {
            ret.push_back({lower, upper});
        }
        if (intervals.size() > 0 && intervals.back()[1] < newInterval[0]) {
            ret.push_back({newInterval});
        }
        return ret;
    }
};

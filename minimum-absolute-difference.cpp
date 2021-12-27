// https://leetcode.com/problems/minimum-absolute-difference/

#include "header.h"

// 实现了一个计数排序，但没有提高成绩

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int NUMBER_LIMIT = 2000001;
        int count = arr.size();
        int min_diff = INT_MAX;
        vector<vector<int>> ret;

        if (count > 100000) {
            bitset<NUMBER_LIMIT> bs;
            for (int i = 0; i < count; i++) {
                bs.set(arr[i] + 1000000);
            }
            int pos = 0;
            int last = INT_MIN;
            for (int i = 0; i < NUMBER_LIMIT; i++) {
                if (bs[i]) {
                    arr[pos++] = i - 1000000;
                    if (last != INT_MIN && i - last < min_diff) {
                        min_diff = i - last;
                    }
                    last = i;
                }
            }
        } else {
            sort(arr.begin(), arr.end());

            int last = arr[0];
            for (int i = 1; i < count; i++) {
                int current = arr[i];
                if (current - last < min_diff) {
                    min_diff = current - last;
                }
                last = current;
            }
        }
        
        int last = arr[0];
        for (int i = 1; i < count; i++) {
            int current = arr[i];
            if (current - last == min_diff) {
                ret.push_back({last, current});
            }
            last = current;
        }
        
        return ret;
    }
};


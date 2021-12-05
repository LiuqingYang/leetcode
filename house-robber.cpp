// https://leetcode.com/problems/house-robber/submissions/


#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int count = nums.size();
        int last_rub = nums[0];
        int last_unrub = 0;
        for (int i = 1; i < count; i++) {
            int rub = last_unrub + nums[i];
            last_unrub = max(last_rub, last_unrub);
            last_rub = rub;
        }
        return max(last_rub, last_unrub);
    }
};

// https://leetcode.com/problems/3sum-closest/submissions/

#include "header.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = nums[0] + nums[1] + nums[2];
        int closest = INT_MAX;
        int count = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < count - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int inner_target = target - nums[i];
            int p1 = i + 1;
            int p2 = count - 1;
            while (p1 < p2) {
                int delta = nums[p1] + nums[p2] - inner_target;
                int abs_delta = abs(delta);
                if (abs_delta < closest) {
                    ret = nums[i] + nums[p1] + nums[p2];
                    closest = abs_delta;
                    if (closest == 0) {
                        return ret;
                    }
                }
                if (delta > 0) {
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        
        return ret;
    }
};
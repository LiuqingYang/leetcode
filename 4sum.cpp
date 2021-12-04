// https://leetcode.com/problems/4sum/

#include "header.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int count = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < count - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < count - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int p1 = j + 1;
                int p2 = count - 1;
                int inner_target = target - nums[i] - nums[j];
                while (p1 < p2) {
                    int sum = nums[p1] + nums[p2];
                    if (sum < inner_target) {
                        p1++;
                        while (p1 < count && nums[p1] == nums[p1-1]) p1++;
                    } else if (sum > inner_target) {
                        p2--;
                        while (p2 > j && nums[p2] == nums[p2+1]) p2--;
                    } else {
                        ret.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        p1++;
                        while (p1 < count && nums[p1] == nums[p1-1]) p1++;
                        p2--;
                        while (p2 > j && nums[p2] == nums[p2+1]) p2--;
                    }
                }
            }
        }
        
        return ret;
    }
};

// https://leetcode.com/problems/3sum/
// Yang Liuqing
// yllqq@outlook.com

// 查找两数合为0可通过首尾双指针优化

#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int count = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < count - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = count - 1; j >= i + 2; j--) {
                if (j != count - 1 && nums[j] == nums[j+1]) continue;
                if (binary_search(nums.begin() + i + 1, nums.begin() + j, -(nums[i] + nums[j]))) {
                    auto vec = {nums[i], -(nums[i] + nums[j]), nums[j]};
                    ret.push_back(vec);
                }
            }
        }
        
        return ret;
    }
};
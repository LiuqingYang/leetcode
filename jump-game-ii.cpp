// https://leetcode.com/problems/jump-game-ii/

#include "header.h"

// 花了一定时间优化为线性解法，若我做笔记尝试，可以直接编写优化后代码

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = nums.size();
        if (count == 1) return 0;
        
        int current_jump = 0;
        int current_jump_max = 0;
        int next_jump_max = 0;
        
        for (int i = 0; i < count; i++) {
            int num = nums[i];
            if (num + i >= count - 1) {
                return current_jump + 1;
            }
            
            next_jump_max = max(next_jump_max, num + i);
            if (i == current_jump_max) {
                current_jump++;
                current_jump_max = next_jump_max;
            }
        }
        return INT_MAX;
    }
};
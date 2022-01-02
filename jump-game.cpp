// https://leetcode.com/problems/jump-game/

#include "header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = nums.size();
        if (count == 1) return true;
        
        int current_jump = 0;
        int current_jump_max = 0;
        int next_jump_max = 0;
        
        for (int i = 0; i < count; i++) {
            int num = nums[i];
            if (num + i >= count - 1) {
                return true;
            }
            
            next_jump_max = max(next_jump_max, num + i);
            if (i == current_jump_max) {
                if (num == 0 && next_jump_max <= i) {
                    return false;
                }
                current_jump++;
                current_jump_max = next_jump_max;
            }
        }
        return false;
    }
};

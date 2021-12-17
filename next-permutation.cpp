// https://leetcode.com/problems/next-permutation/

#include "header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int count = nums.size();
        int p = count - 1;
        
        while (p > 0 && nums[p - 1] >= nums[p]) p--;
        
        if (p == 0) {
            // reverse
            int q = count - 1;
            while (p < q) {
                swap(nums[p], nums[q]);
                p++;
                q--;
            }
             return;
        } else if (p == count - 1) {
            swap(nums[p], nums[p - 1]);
            return;
        }
        
        p--;
        int nump = nums[p];
        int min_delta = 101;
        int min_delta_pos;
        
        for (int i = count - 1; i > p; i--) {
            int delta = nums[i] - nump;
            if (delta > 0 && delta < min_delta) {
                min_delta = delta;
                min_delta_pos = i;
            }
        }
        
        swap(nums[p], nums[min_delta_pos]);

        p++;
        int q = count - 1;
        while(p < q) {
            swap(nums[p], nums[q]);
            p++;
            q--;
        }
    }
};
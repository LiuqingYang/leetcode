https://leetcode.com/problems/permutations/

#include "header.h"

class Solution {
private:
    vector<vector<int>> ret;

    void inner(vector<int>& nums, int start) {
        int count = nums.size();
        if (start == count) {
            ret.push_back(nums);
        }
        
        for (int i = start; i < count; i++) {
            swap(nums[start], nums[i]);
            inner(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ret.clear();
        inner(nums, 0);
        return ret;
    }
};

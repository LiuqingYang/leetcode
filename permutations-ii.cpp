// https://leetcode.com/problems/permutations-ii/

#include "header.h"

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> stk;

    void inner(vector<int>& nums, int start) {
        int count = nums.size();
        if (start == count) {
            ret.push_back(nums);
            return;
        }
        
        for (int i = start; i < count;) {
            int i_max = i + 1;
            while (i_max < count && nums[i_max] == nums[i]) i_max++;
            
            swap(nums[start], nums[i]);
            inner(nums, start + 1);
            i = i_max;
        }
        
        int first = nums[start];
        int first_size = 1;
        while((start + first_size < count) && nums[start + first_size] == first) first_size++;
        if (start + first_size != count) {
            nums.erase(nums.begin() + start, nums.begin() + start + first_size);
            nums.resize(count, first);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ret.clear();
        sort(nums.begin(), nums.end());
        inner(nums, 0);
        return ret;
    }
};

int main() {
    vector<int> nums = {1,1,2,2};
    Solution sol;
    sol.permuteUnique(nums);
}
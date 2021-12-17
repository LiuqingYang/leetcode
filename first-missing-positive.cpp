// https://leetcode.com/problems/first-missing-positive/

#include "header.h"


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            int num = nums[i];
            while (num > 0 && num <= count && i != num - 1 && num != nums[num - 1]) {
                swap(nums[i], nums[num - 1]);
                num = nums[i];
            }
        }
        
        for (int i = 0; i < count; i++) {
            if (nums[i] <= 0 || nums[i] - 1 != i) {
                return i + 1;
            }
        }
        return count + 1;
    }
};


/*
// 此方案使用了一些额外内存
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int MAX_LEN = 5 * 1e5 + 1;
        bitset<MAX_LEN> bs(0);
        
        for (auto num : nums) {
            if (num > 0 && num < MAX_LEN) {
                bs[num] = true;
            }
        }
        
        for (int i = 1; i < MAX_LEN; i++) {
            if (!bs[i]) {
                return i;
            }
        }
        return MAX_LEN;
    }
};
*/
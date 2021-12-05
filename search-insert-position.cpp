// https://leetcode.com/problems/search-insert-position/

#include "header.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t start = 0;
        size_t end = nums.size();
        
        while(1) {
            if ((end - start) == 1) {
                if (target <= nums[start]) return start;
                else return start + 1;
            }
            
            size_t mid = (start + end) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) end = mid;
            else start = mid;
        }
    }
};
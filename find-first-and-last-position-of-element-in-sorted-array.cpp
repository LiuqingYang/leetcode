// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        auto start = nums.begin();
        auto end = nums.end();
        
        if (nums.size() == 0) { return {-1, -1}; }
        
        while (start < end - 1) {
            auto mid = start + (end - start) / 2;
            if (*mid >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        cout << start - nums.begin();
        if (*start == target) {
            result.push_back(start - nums.begin());
        } else if ((start + 1) < nums.end() && *(start + 1) == target) {
            result.push_back(start + 1 - nums.begin());
        } else {
            return {-1, -1};
        }
        
        start = nums.begin();
        end = nums.end();
        while (start < end - 1) {
            auto mid = start + (end - start) / 2;
            if (*mid > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        cout << start - nums.begin();
        if (*start == target) {
            result.push_back(start - nums.begin());
        } else if (start > nums.begin() && *(start - 1) == target) {
            result.push_back(start - 1 - nums.begin());
        } else {
            return {-1, -1};
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    sol.searchRange(nums, 8);
}
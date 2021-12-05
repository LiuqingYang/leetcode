// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include "header.h"

class Solution {
private:
    int m_rotate_index = 0;
    vector<int>* m_nums;
    
    int num(int index) {
        int idx = (index + m_rotate_index) % m_nums->size();
        return (*m_nums)[idx];
    }
public:
    int search(vector<int>& nums, int target) {
        m_nums = &nums;
        
        int count = nums.size();
        int p1 = 0;
        int p2 = count - 1;
        
        int target_index = -1;
        
        if (nums[p1] > nums[p2]) {
            while (p1 < p2) {
                if (p2 - p1 == 1) {
                    if (nums[p1] > nums[p2]) {
                        m_rotate_index = p2;
                        break;
                    }
                }
                int mid = (p1 + p2) / 2;
                if (nums[p1] > nums[mid]) {
                    p2 = mid;
                } else if (nums[mid] > nums[p2]) {
                    p1 = mid;
                }
            }
        }
        
        p1 = 0;
        p2 = count;
        while (p1 < p2) {
            if (p2 - p1 == 1) {
                if (num(p1) == target) {
                    return (p1 + m_rotate_index) % count;
                } else {
                    return -1;
                }
            }
            int mid = (p1 + p2) / 2;
            if (target < num(mid)) {
                p2 = mid;
            } else {
                p1 = mid;
            }
        }
        return -1;
    }
};
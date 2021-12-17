// https://leetcode.com/problems/trapping-rain-water/

#include "header.h"

class Solution {
public:
    void trap_inner_incr(vector<int>& height, int end, int max, int max_pos, int &ret) {
        if (max_pos == end) return;
        
        int max_inner = height[end];
        int max_pos_inner = end;
        
        for (int i = end - 1; i > max_pos; i--) {
            if (height[i] > max_inner) {
                max_inner = height[i];
                max_pos_inner = i;
            }
        }
        
        for (int i = max_pos + 1; i < max_pos_inner; i++) {
            if (height[i] < max_inner) {
                ret += max_inner - height[i];
            }
        }
        
        return trap_inner_incr(height, end, max_inner, max_pos_inner, ret);
    }
    
    void trap_inner_decr(vector<int>& height, int begin, int max, int max_pos, int &ret) {
        if (max_pos == begin) return;
        
        int max_inner = height[begin];
        int max_pos_inner = begin;
        
        for (int i = 1; i < max_pos; i++) {
            if (height[i] > max_inner) {
                max_inner = height[i];
                max_pos_inner = i;
            }
        }
        
        for (int i = max_pos - 1; i > max_pos_inner; i--) {
            if (height[i] < max_inner) {
                ret += max_inner - height[i];
            }
        }
        
        return trap_inner_decr(height, begin, max_inner, max_pos_inner, ret);
    }
    
    int trap(vector<int>& height) {
        int count = height.size();
        int max = height[0];
        int max_pos = 0;
            
        for (int i = 1; i < count; i++) {
            if (height[i] > max) {
                max = height[i];
                max_pos = i;
            }
        }
        
        int begin = 0;
        while (begin < max_pos && height[begin] < height[begin + 1]) {
            begin++;
        }
        
        
        int end = count - 1;
        while (end > max_pos && height[end] < height[end - 1]) {
            end --;
        }
        
        int ret1 = 0;
        int ret2 = 0;
        trap_inner_incr(height, end, max, max_pos, ret1);
        trap_inner_decr(height, begin, max, max_pos, ret2);
        
        return ret1 + ret2;
    }
};

/*
simple answer two pointer
运行速度和内存占用和我写的基本一致，但特殊测试用例比我的更好

    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }

*/
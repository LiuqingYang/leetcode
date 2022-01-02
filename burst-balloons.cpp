// https://leetcode.com/problems/burst-balloons/

#include "header.h"

// 逆向思维对动态规划（甚至所有算法）而言非常重要，简化此题至二维空间复杂度和三维时间复杂度
// 在正向思考超过一定时长后，要试着换种方式
// 设置额外边界元素不仅有利于思考，也有利于减少判断以提高速度，仅需少量的额外空间消耗

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> result;  // start end
        
        auto it = remove(nums.begin(), nums.end(), 0);
        nums.erase(it, nums.end());
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int count = nums.size() - 2;
        result.resize(count + 2);
        
        for (int i = 0; i < count + 2; i++) {
            result[i].resize(count + 2);
        }
        
        for (int len = 0; len < count; len++) {
            for (int start = 1; start < count - len + 1; start++) {
                int end = start + len;
                int& curr = result[start][end];
                for (int i = start; i <= end; i++) {  // last burst i
                    int coin = nums[start-1] * nums[i] * nums[end+1] + result[start][i - 1] + result[i + 1][end];
                    curr = max(curr, coin);
                }
            }
        }
        return result[1][count];
    }
};
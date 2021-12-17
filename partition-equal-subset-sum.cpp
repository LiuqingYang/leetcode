// https://leetcode.com/problems/partition-equal-subset-sum/

#include "header.h"

// 我的方案此题运行时间：set > unordered_set > vector

// other solution: https://leetcode.com/problems/partition-equal-subset-sum/discuss/90588/Concise-C%2B%2B-Solution-summary-with-DFS-DP-BIT
// 只考虑一边的和为sum/2是极大的优化，使得能够使用较快的DP算法
// 使用bitset相关操作能够最快解决，但思路和DP算法一样

class Solution {
public:
    void partition(int current, vector<int>& in, vector<int>& out) {
        for (auto i : in) {
            out.push_back(abs(i + current));
            out.push_back(abs(i - current));
        }
        sort(out.begin(), out.end() );
        out.erase(unique(out.begin(), out.end() ),out.end());
    }
    
    bool canPartition(vector<int>& nums) {
        vector<int> in;
        vector<int> out;
        
        in.push_back(nums[0]);
        int count = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            partition(nums[i], in, out);
            in.clear();
            in.swap(out);
        }
        return in[0] == 0;
    }
};

/*
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
    if (sum & 1) return false;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(auto num : nums) 
        for(int i = target; i >= num; i--)
            dp[i] = dp[i] || dp[i - num];
    return dp[target];
}
*/

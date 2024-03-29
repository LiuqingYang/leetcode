// https://leetcode.com/problems/unique-paths/

#include "header.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);  // speed up
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n - 1];
    }
};
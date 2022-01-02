// https://leetcode.com/problems/unique-paths-ii/

#include "header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<int> dp(column);
        
        for (int i = 0; i < row; i++) {
            vector<int>& curr = obstacleGrid[i];
            dp[0] = dp[0] && (curr[0] ? 0 : 1);
            for (int j = 1; j < column; j++) {
                if (curr[j]) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return dp[column - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 1}, {0, 0}};
    sol.uniquePathsWithObstacles(grid);
}
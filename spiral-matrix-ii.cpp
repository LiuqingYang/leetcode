// https://leetcode.com/problems/spiral-matrix-ii/

#include "header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<pair<int, int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> times{n, n-1, n-1, n-2};
        
        vector<vector<int>> ret;        
        ret.resize(n);
        for (int i = 0; i < n; i++) {
            ret[i].resize(n);
        }
        
        int num = 0;
        int x = 0;
        int y = -1;
        int target = n * n;
        int dir = 0;
        while (num < target) {
            int time = times[dir];
            for (int i = 0; i < time; i++) {
                x += direction[dir].first;
                y += direction[dir].second;
                ret[x][y] = ++num;
            }
            times[dir] -= 2;
            dir = (dir + 1) % 4;
        }
        return ret;
    }
};

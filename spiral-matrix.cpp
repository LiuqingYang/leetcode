// https://leetcode.com/problems/spiral-matrix/

#include "header.h"

// 每个方向前进的值可以算出来，即可以简化代码

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int magic = -101;
        // (0, 1) (1, 0) (0 -1) (-1 0)
        int direct = 0;
        
        vector<int> ret;
        int row = matrix.size();
        int column = matrix[0].size();
        int max_num = row * column;
        
        ret.push_back(matrix[0][0]);
        matrix[0][0] = magic;
        int current = 1;
        int i = 0;
        int j = 0;
        while(current < max_num) {
            if (direct == 0) {
                if (j + 1 < column) {
                    int num = matrix[i][j+1];
                    if (num != magic) {
                        j++;
                        ret.push_back(num);
                        matrix[i][j] = magic;
                        ++current;
                        continue;
                    }
                }
                direct = 1;
            } else if (direct == 1) {
                if (i + 1 < row) {
                    int num = matrix[i+1][j];
                    if (num != magic) {
                        i++;
                        ret.push_back(num);
                        matrix[i][j] = magic;
                        ++current;
                        continue;
                    }
                }
                direct = 2;
            } else if (direct == 2) {
                if (j - 1 >= 0) {
                    int num = matrix[i][j-1];
                    if (num != magic) {
                        j--;
                        ret.push_back(num);
                        matrix[i][j] = magic;
                        ++current;
                        continue;
                    }
                }
                direct = 3;
            } else if (direct == 3) {
                if (i - 1 >= 0) {
                    int num = matrix[i-1][j];
                    if (num != magic) {
                        i--;
                        ret.push_back(num);
                        matrix[i][j] = magic;
                        ++current;
                        continue;
                    }
                }
                direct = 0;
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> matrix = {{1}};
    Solution sol;
    sol.spiralOrder(matrix);
}
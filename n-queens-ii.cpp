// https://leetcode.com/problems/n-queens-ii/

#include "header.h"

// 可以进一步将string改为vector<bool>，缩减内存占用

class Solution {
private:
    int inner(int n, vector<string>& board) {
        int top = board.size();
        int row = n - board.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < top; j++) {
                string& line_j = board[j];
                int d = top - j;
                if (line_j[i] == 'Q' || (i - d >= 0 && line_j[i - d] == 'Q') || (i + d < n && line_j[i + d] == 'Q')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            if (top + 1 != n)
            {
                string line(n, '.');
                line[i] = 'Q';
                board.push_back(line);
                result += inner(n, board);
                board.pop_back();
            }
            else
            {
                return 1;
            }
        }
        return result;
    }
public:
    int totalNQueens(int n) {
        vector<string> board;
        
        return inner(n, board);
    }
};
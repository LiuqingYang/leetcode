// https://leetcode.com/problems/n-queens/

#include "header.h"

// 可以记录斜、直、反斜三条线的状态，但没有复杂度上的优势，且以下解法已经0ms了

class Solution {
private:
    void inner(int n, vector<vector<string>>& result, vector<string>& board) {
        int top = board.size();
        int row = n - board.size();
        
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
            string line(n, '.');
            line[i] = 'Q';
            board.push_back(line);
            
            if (top + 1 != n)
            {
                inner(n, result, board);
            }
            else
            {
                result.push_back(board);
            }
            board.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        
        inner(n, result, board);
        return result;
    }
};
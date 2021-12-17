// https://leetcode.com/problems/maximal-square/

#include "header.h"

// 我的首个算法以及很像完美的dp解了，甚至所需时间没有明显变长，只是要注意尽量优化为使用原始数组（或矩阵）来表示之前的状态，而非较为复杂的结构体
// 面试时基本只会考察最终代码较短的题目
/*
class Solution {
public:
    struct Ones {
        short start;
        short end;  // position after last one
        short line = 1;
        Ones(short a, short b) {start = a; end = b;}
        Ones(short a, short b, short c) {start = a; end = b; line = c;}
    };
    
    short ParseLine(vector<char>& line, vector<Ones>& ones, short max_len) {
        int current = -1;
        int count = line.size();
        
        for (int i = 0; i < count; i++) {
            if (line[i] == '1') {
                if (current == -1) {
                    current = i;
                }
            } else {
                if (current != -1) {
                    if (max_len == 0) max_len = 1;
                    if (i - current > max_len) {
                        ones.emplace_back(current, i);
                    }
                    current = -1;
                }
            }
        }
        if (current != -1) {
            if (max_len == 0) max_len = 1;
            if (count - current > max_len) {
                ones.emplace_back(current, count);
            }
        }
        return max_len;
    }
    
    short MergeOnes(vector<Ones>& remain, vector<Ones>& line, short max_len) {
        vector<Ones> new_remain;
        
        for (auto remain_it = remain.begin(); remain_it != remain.end(); ++remain_it) {
            for (auto line_it = line.begin(); line_it != line.end(); ++line_it) {
                short new_start = max(line_it->start, remain_it->start);
                short new_end = min(line_it->end, remain_it->end);
                if (new_end - new_start > max_len) {
                    short new_line = remain_it->line + 1;
                    if (new_line == new_end - new_start) {
                        max_len = new_line;
                    } else if (new_line < new_end - new_start) {
                        new_remain.emplace_back(new_start, new_end, new_line);
                        max_len = max(max_len, new_line);
                    }
                }
            }
        }

        for (auto line_it = line.begin(); line_it != line.end(); ++line_it) {
            bool have = false;
            for (auto remain_it = new_remain.begin(); remain_it != new_remain.end(); ++remain_it) {
                if (remain_it->start == line_it->start && remain_it->end == line_it->end) {
                    have = true;
                    break;
                }
            }
            if (!have) {
                new_remain.push_back(*line_it);
            }
        }

        remain.swap(new_remain);
        return max_len;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        short max_len = 0;
        int line_count = matrix.size();
        vector<Ones> remain_ones;
        
        for (int i = 0; i < line_count; i++) {
            vector<Ones> ones;
            max_len = ParseLine(matrix[i], ones, max_len);
            
            max_len = MergeOnes(remain_ones, ones, max_len);
        }
        
        return max_len * max_len;
    }
};
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row_count = matrix.size();
        int col_count = matrix[0].size();
        vector<short> prev(col_count, 0);
        short max_matr = 0;
        
        for (int i = 0; i < row_count; i++) {
            short last = 0;
            for (int j = 0; j < col_count; j++) {
                bool is_one = (matrix[i][j] == '1');
                if (is_one) {
                    if (j == 0) {
                        last = 1;
                        prev[j] = 1;
                    } else {
                        last = min(last, prev[j - 1]);
                        last = min(last, prev[j]) + 1;
                        prev[j] = last;
                    }
                    max_matr = max(max_matr, last);
                } else {
                    last = 0;
                    prev[j] = 0;
                }
            }
        }
        
        return max_matr * max_matr;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
    
    Solution sol;
    sol.maximalSquare(matrix);
}
// https://leetcode.com/problems/sudoku-solver/

#include "header.h"

class Solution {
private:
    struct Cell {
        bool solve = false;
        char answer = -1;
        bool impossible[9] = {};
        bool guess = false;
        Cell(char c) {
            if (c != '.') {
                solve = true;
                answer = c - '1';
            }
        }
        Cell() {}
    };
    struct TryCell {
        int a;
        int b;
        char answer;
        vector<vector<Cell>> ori_board;
    };
    vector<vector<Cell>> m_board;
    vector<TryCell> m_try_stack;

    static pair<int, int> getRow(int a, int b) { return make_pair(a, b); }
    static pair<int, int> getColumn(int a, int b) { return make_pair(b, a); }
    static pair<int, int> getGrid(int a, int b) { return make_pair(((a / 3) * 3 + b / 3), ((a % 3) * 3 + (b % 3))); }
    typedef pair<int, int> (*func_get)(int, int);

    int parse(func_get func) {
        int ret = 0;
        for (int i = 0; i < 9; i++) {
            bool impossible[9] = {};
            for (int j = 0; j < 9; j++) {
                pair<int, int> pos = func(i, j);
                Cell &c = m_board[pos.first][pos.second];
                if (c.solve) {
                    impossible[c.answer] = true;
                }
            }
            for (int j = 0; j < 9; j++) {
                int row = (i / 3) * 3 + j / 3;
                int column = (i % 3) * 3 + (j % 3);
                pair<int, int> pos = func(i, j);
                Cell &c = m_board[pos.first][pos.second];
                if (!c.solve) {
                    char answer = -1;
                    for (int k = 0; k < 9; k++) {
                        if (impossible[k] && !c.impossible[k]) ret += 1;
                        c.impossible[k] |= impossible[k];
                        if (!c.impossible[k]) {
                            if (answer == -1) {
                                answer = k;
                            } else {
                                answer = -2;
                            }
                        }
                    }
                    if (answer >= 0) {
                        c.solve = true;
                        c.answer = answer;
                        memset(c.impossible, true, 9);
                    }
                }
                if (!c.solve) {
                    for (int k = 0; k < 9; k++) {
                        if (!c.impossible[k]) {
                            bool only_possible = true;
                            for (int l = 0; l < 9; l++) {
                                if (l != j) {
                                    pair<int, int> pos = func(i, l);
                                    Cell &c_l = m_board[pos.first][pos.second];
                                    if (!c_l.impossible[k]) {
                                        only_possible = false;
                                        break;
                                    }
                                }
                            }
                            if (only_possible) {
                                ret += 1;
                                c.solve = true;
                                c.answer = k;
                                memset(c.impossible, true, 9);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }

    int valid(func_get func) {
        bool solve = true;
        for (int i = 0; i < 9; i++) {
            bool answers[9] = {};
            for (int j = 0; j < 9; j++) {
                pair<int, int> pos = func(i, j);
                Cell &c = m_board[pos.first][pos.second];
                if (!c.solve) {
                    solve = false;
                    bool possible = false;
                    for (int k = 0; k < 9; k++) {
                        if (!c.impossible[k]) {
                            possible = true;
                        }
                    }
                    if (!possible) {
                        return 1;
                    }
                } else {
                    answers[c.answer] = true;
                }
            }
            if (solve) {
                for (int j = 0; j < 9; j++) {
                    if (!answers[j]) {
                        return 1;
                    }
                }
            }
        }
        return solve ? 0 : 2;
    }

    bool guess() {
        int min_i;
        int min_j;
        int min = 20;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                Cell &c = m_board[i][j];
                if (!c.guess && !c.solve) {
                    int count = 0;
                    for (int k = 0; k < 9; k++) {
                        if (!c.impossible[k]) {
                            count++;
                        }
                    }
                    if (count > 0 && count < min) {
                        min_i = i;
                        min_j = j;
                        min = count;
                    }
                }
            }
        }
        if (min < 20) {
            Cell& c = m_board[min_i][min_j];
            for (int k = 0; k < 9; k++) {
                if (!c.impossible[k]) {
                    TryCell tc = {min_i, min_j, (char)k};
                    m_try_stack.push_back(tc);
                    copyVec(m_try_stack.back().ori_board, m_board);

                    c.guess = true;
                    c.solve = true;
                    c.answer = k;
                    memset(c.impossible, true, 9);
                    return true;
                }
            }
        } 
        return false;
    }
    
    void copyVec(vector<vector<Cell>>& to, vector<vector<Cell>>& from) {
        for (int i = 0; i < 9; i++) {
            to.resize(9);
            for (int j = 0; j < 9; j++) {
                to[i].resize(9);
                to[i][j] = from[i][j];
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        m_board.resize(9);
        for (int i = 0; i < 9; i++) {
            m_board[i].resize(9);
            for (int j = 0; j < 9; j++) {
                m_board[i][j] = board[i][j];
            }
        }
        
        while (1) {
            while (1) {
                int ret = 0;
                ret += parse(getRow);
                ret += parse(getColumn);
                ret += parse(getGrid);
                if (ret == 0) break;
            }

            if (m_try_stack.size()) {
                int row = valid(getRow);
                int column = valid(getColumn);
                int grid = valid(getGrid);
                if (row == 1 || column == 1 || grid == 1) {
                    // guess fail
                    TryCell &tc = m_try_stack.back();
                    tc.ori_board[tc.a][tc.b].impossible[tc.answer] = true;
                    tc.ori_board[tc.a][tc.b].guess = false;
                    // printf("guess fail: %d:%d %d\n", tc.a, tc.b, tc.answer);
                    copyVec(m_board, tc.ori_board);
                    m_try_stack.pop_back();
                    continue;
                }
                if (row == 2 || column == 2 || grid == 2) {
                    // continue guess
                    if (guess()) {
                        continue;
                    } else {
                        // guess fail
                        TryCell &tc = m_try_stack.back();
                        tc.ori_board[tc.a][tc.b].impossible[tc.answer] = true;
                        tc.ori_board[tc.a][tc.b].guess = false;
                        // printf("guess fail: %d:%d %d\n", tc.a, tc.b, tc.answer);
                        copyVec(m_board, tc.ori_board);
                        m_try_stack.pop_back();
                        continue;
                    }
                }
            }
            
            bool finish = true;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    Cell &c = m_board[i][j];
                    if (c.solve) {
                        board[i][j] = m_board[i][j].answer + '1';
                    } else {
                        finish = false;
                        break;
                    }
                }
                if (!finish) break;
            }

            if (finish) break;

            // first guess
            guess();
        }
    }
};

int main() {
    vector<vector<char>> board {{'.','.','.','2','.','.','.','6','3'},{'3','.','.','.','.','5','4','.','1'},{'.','.','1','.','.','3','9','8','.'},{'.','.','.','.','.','.','.','9','.'},{'.','.','.','5','3','8','.','.','.'},{'.','3','.','.','.','.','.','.','.'},{'.','2','6','3','.','.','5','.','.'},{'5','.','3','7','.','.','.','.','8'},{'4','7','.','.','.','1','.','.','.'}};

    Solution sol;
    sol.solveSudoku(board);
}
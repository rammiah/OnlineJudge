#include <vector>
#include <iostream>
#include <string.h>
using std::vector;
using std::cout;

bool is_o[1000][1000];

class Solution {
    int row_limit, col_limit;
    void dfs(int row, int col, vector<vector<char>> &board) {
        if (row < 0 || col < 0 || row >= row_limit || col >= col_limit) {
            return;
        }
        if (is_o[row][col]) {
            return;
        }
        if (board[row][col] == 'O') {
            is_o[row][col] = true;
            dfs(row - 1, col, board);
            dfs(row + 1, col, board);
            dfs(row, col - 1, board);
            dfs(row, col + 1, board); 
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        // 变量覆盖害死人，Java NB
        row_limit = board.size();
        col_limit = board[0].size();
        memset(is_o, 0, sizeof(is_o));
        for (int row = 0; row < row_limit; ++row) {
            dfs(row, 0, board);
            dfs(row, col_limit - 1, board);
        }

        for (int col = 0; col < col_limit; ++col) {
            dfs(0, col, board);
            dfs(row_limit - 1, col, board);
        }
        // dfs(row, col, board);
        // 开始更改
        for (int row = 0; row < row_limit; ++row) {
            for (int col = 0; col < col_limit; ++col) {
                board[row][col] = is_o[row][col] ? 'O' : 'X';
            }
        }
    }
};

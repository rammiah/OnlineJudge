// Hello.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int col_limit, row_limit;
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (col < 0 || col >= col_limit || row < 0 || row >= row_limit) {
            return;
        }
        if (grid[row][col] == '1') {
            grid[row][col] = '0';
            dfs(grid, row - 1, col);
            dfs(grid, row + 1, col);
            dfs(grid, row, col - 1);
            dfs(grid, row, col + 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // DFS不解释
        row_limit = grid.size();
        if (row_limit == 0) {
            return 0;
        }
        col_limit = grid[0].size();
        if (col_limit == 0) {
            return 0;
        }
        int result = 0;
        auto copy(grid);
        for (int i = 0; i < row_limit; i++) {
            for (int j = 0; j < col_limit; ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }
};

int main() {
    std::cout << "Hello world.\n";

    return 0;
}


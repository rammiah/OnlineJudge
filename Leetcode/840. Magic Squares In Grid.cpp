#include <vector>

using namespace std;

class Solution {
    bool chk(vector<vector<int>>& grid, int row, int col) {
        /// 传参保证grid[row][col]是5
        // 计算数字是否到齐了
        long long bits = 0;
        long long yes = 0b1111111110;
        bits |= 1L << grid[row - 1][col - 1];
        bits |= 1L << grid[row - 1][col];
        bits |= 1L << grid[row - 1][col + 1];
        bits |= 1L << grid[row][col - 1];
        bits |= 1L << grid[row][col];
        bits |= 1L << grid[row][col + 1];
        bits |= 1L << grid[row + 1][col - 1];
        bits |= 1L << grid[row + 1][col];
        bits |= 1L << grid[row + 1][col + 1];
        if ((bits ^ yes) != 0) {
            return false;
        }
        // 计算和是否正确
        // 一定是15
        // 横竖都对，斜的一定没问题
        for (int i = row - 1; i < row + 2; ++i) {
            if (grid[i][col - 1] + grid[i][col] + grid[i][col  + 1] != 15) {
                return false;
            }
        }
        for (int i = col - 1; i < col + 2; ++i) {
            if (grid[row - 1][i] + grid[row][i] + grid[row + 1][i] != 15) {
                return false;
            }
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // 有个结论，中间的那个数一定是5，否则不可能
        if (grid.size() < 3) {
            return 0;
        }
        int limit = grid.size();
        int result = 0;
        for (int i = 1; i < limit - 1; ++i) {
            for (int j = 1; j < limit - 1; ++j) {
                if (grid[i][j] == 5) {
                    result += chk(grid, i, j) ? 1 : 0;
                }
            }
        }

        return result;
    }
};
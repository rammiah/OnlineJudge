class Solution {
    int get_ave(vector<vector<int>> &v, int r0, int r1, int c0, int c1) {
        int sum = 0;
        for (int i = r0; i < r1; ++i) {
            for (int j = c0; j < c1; ++j) {
                sum += v[i][j];
            }
        }
        return sum / ((r1 - r0) * (c1 - c0));
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &v) {
        vector<vector<int>> res = v;
        int row = v.size(), col = v[0].size();
        if (row == 1 && col == 1) {
            return res;
        } else if (row == 1 && col > 1) {
            res[0][0] = get_ave(v, 0, 1, 0, 2);
            res[0][col - 1] = get_ave(v, 0, 1, col - 2, col);
            for (int i = 1; i < col - 1; ++i) {
                res[0][i] = get_ave(v, 0, 1, i - 1, i + 2);
            }
        } else if (row > 1 && col == 1) {
            res[0][0] = get_ave(v, 0, 2, 0, 1);
            res[row - 1][0] = get_ave(v, row - 2, row, 0, 1);
            for (int i = 1; i < row - 1; ++i) {
                res[i][0] = get_ave(v, i - 1, i + 2, 0, 1);
            }
        } else {
            res[0][0] = get_ave(v, 0, 2, 0, 2);
            res[0][col - 1] = get_ave(v, 0, 2, col - 2, col);
            res[row - 1][0] = get_ave(v, row - 2, row, 0, 2);
            res[row - 1][col - 1] = get_ave(v, row - 2, row, col - 2, col);
            for (int i = 1; i < col - 1; ++i) {
                res[0][i] = get_ave(v, 0, 2, i - 1, i + 2);
                res[row - 1][i] = get_ave(v, row - 2, row, i - 1, i + 2);
            }

            for (int i = 1; i < row - 1; ++i) {
                res[i][0] = get_ave(v, i - 1, i + 2, 0, 2);
                res[i][col - 1] = get_ave(v, i - 1, i + 2, col - 2, col);
                for (int j = 1; j < col - 1; ++j) {
                    res[i][j] = get_ave(v, i - 1, i + 2, j - 1, j + 2);
                }
            }
        }

        return res;
    }
};

class Solution {
    void update(int &a, int b) {
        a = max(a, b);
    }
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int sum = 0;
        int limit = grid.size();
        vector<int> row_max(limit, 0);
        vector<int> col_max(limit, 0);
        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                update(row_max[i], grid[i][j]);
            }
        }              
        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                update(col_max[i], grid[j][i]);
            }
        }

        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                sum += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }

        return sum;
    }
};
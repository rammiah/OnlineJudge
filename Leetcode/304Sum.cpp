class NumMatrix {
private:
    long long sum[1000][1000];
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int row = matrix.size(), col = matrix[0].size();
        sum[0][0] = matrix[0][0];
        for (int i = 1; i < row; ++i) {
            sum[i][0] = matrix[i][0] + sum[i - 1][0];
        }
        for (int i = 1; i < col; ++i) {
            sum[0][i] = matrix[0][i] + sum[0][i - 1];
        }

        for (int i = 1; i <row; ++i) {
            for (int j = 1; j < col; ++j) {
                sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 >= 1) {
            if (col1 >= 1) {
                return sum[row2][col2] + sum[row1 - 1][col1 - 1] - sum[row2][col1 - 1] - sum[row1 - 1][col2];
            } else {
                return sum[row2][col2] - sum[row1 -1][col2];
            }
        } else {
            if (col1 >= 1) {
                return sum[row2][col2] - sum[row2][col1 - 1];
            } else {
                return sum[row2][col2];
            }
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
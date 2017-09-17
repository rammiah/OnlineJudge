// 073 set zeroes
class Solution {
    public void setZeroes(int[][] matrix) {
        final int rows = matrix.length, cols = matrix[0].length;
        boolean[] to_set_rows = new boolean[rows], to_set_cols = new boolean[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    to_set_rows[i] = true;
                    to_set_cols[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            if (to_set_rows[i]) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < cols; i++) {
            if (to_set_cols[i]) {
                for (int j = 0; j < rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}


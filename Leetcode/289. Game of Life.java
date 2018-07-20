class Solution {

    int getNeighbors(int[][] board, int row, int col, int rowLimit, int colLimit) {
        int res = 0;
        for (int i = Math.max(0, row - 1); i <= Math.min(rowLimit - 1, row + 1); i++) {
            for (int j = Math.max(0, col - 1); j <= Math.min(colLimit - 1, col + 1); j++) {
                    res += board[i][j];
            }
        }
        return res - board[row][col];
    }

    public void gameOfLife(int[][] board) {
        if (board == null || board[0].length == 0) {
            return;
        }
        int row = board.length, col = board[0].length;
        int[][] helper = new int[row][col];
        /*
         * 活细胞
         * 2,3: 活
         * 其他: 死
         * 死细胞
         * 3: 复活
         * 其他: 死
         * */
        int neighbors;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                neighbors = getNeighbors(board, i, j, row, col);
                        // System.out.println(neighbors);
                if (board[i][j] == 0 && neighbors == 3) {
                    helper[i][j] = 1;
                } else if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                    helper[i][j] = 1;
                } else {
                    helper[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            System.arraycopy(helper[i], 0, board[i], 0, col);
        }
    }
}

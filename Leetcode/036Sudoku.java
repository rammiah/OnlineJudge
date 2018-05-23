public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] arr = new int[9];
        // 检测行
        for (int i = 0; i < 9; ++i) {
            reset(arr);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (arr[board[i][j] - '1'] == 1) return false;
                    else arr[board[i][j] - '1'] = 1;
                }
            }
        }
        // 检测列
        for (int i = 0; i < 9; i++) {
            reset(arr);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (arr[board[j][i] - '1'] == 1) return false;
                    else arr[board[j][i] - '1'] = 1;
                }
            }
        }
        // 检测小块
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                reset(arr);
                int row = i * 3;
                for (; row < i * 3 + 3; ++row) {
                    int col = j * 3;
                    for (; col < j * 3 + 3; ++col) {
                        if (board[row][col] != '.'){
                            if (arr[board[row][col] - '1'] == 1) return false;
                            else arr[board[row][col] - '1'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
    // 重置数组
    private void reset(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            arr[i] = 0;
        }
    }
}

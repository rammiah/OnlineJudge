// 79 search a word in the char matrix
public class _79SearchWord {
    private int row_limit = 0, col_limit;
    private final char USED = 0;

    public boolean exist(char[][] board, String word) {
        char[] chars = word.toCharArray();
        row_limit = board.length - 1;
        col_limit = board[0].length - 1;
        boolean isFound = false;
        for (int i = 0; i <= row_limit && !isFound; i++) {
            for (int j = 0; j <= col_limit && !isFound; j++) {
                if (board[i][j] == chars[0]) {
                    isFound = search(board, chars, 0, i, j);
                }
            }
        }

        return isFound;
    }

    private boolean search(char[][] board, char[] word, int index, int row, int col) {
        if (row < 0 || row > row_limit || col < 0 || col > col_limit) return false;

        if (board[row][col] == word[index]) {
            if (index == word.length - 1) {
                return true;
            } else {
                char current = board[row][col];
                board[row][col] = USED;
                if (search(board, word, index + 1, row - 1, col)) {
                    return true;
                } else if (search(board, word, index + 1, row + 1, col)) {
                    return true;
                } else if (search(board, word, index + 1, row, col - 1)) {
                    return true;
                } else if (search(board, word, index + 1, row, col + 1)) {
                    return true;
                }
                board[row][col] = current;
                return false;
            }
        }
        return false;
    }

//    public static void main(String[] args) {
//        _79SearchWord sol = new _79SearchWord();
//        char[][] chars = {
//                {'A', 'B', 'C', 'E'},
//                {'S', 'F', 'C', 'S'},
//                {'A', 'D', 'E', 'E'}
//        };
//        System.out.println(sol.exist(chars, "ABCCED"));
//    }
}

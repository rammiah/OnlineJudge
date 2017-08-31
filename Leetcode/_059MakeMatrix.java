/*
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
public class Solution {
    public int[][] generateMatrix(int n) {
        if (n < 0) return null;
        int[][] result = new int[n][n];
        final int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;

        int direction = RIGHT;
        final int SUM = n * n;
        int left_limit = 0, up_limit = 0, right_limit = n - 1, down_limit = n - 1;
        int index = 1;
        int current_row = 0, current_col = 0;

        while (index <= SUM) {
            switch (direction) {
                case RIGHT:
                    current_row = up_limit;
                    for (int i = left_limit; i <= right_limit; ++i) {
                        result[current_row][i] = index++;
                    }
                    ++up_limit;
                    direction = DOWN;
                    break;
                case DOWN:
                    current_col = right_limit;
                    for (int i = up_limit; i <= down_limit; ++i) {
                        result[i][current_col] = index++;
                    }
                    --right_limit;
                    direction = LEFT;
                    break;
                case LEFT:
                    current_row = down_limit;
                    for (int i = right_limit; i >= left_limit; --i) {
                        result[current_row][i] = index++;
                    }
                    --down_limit;
                    direction = UP;
                    break;
                case UP:
                    current_col = left_limit;
                    for (int i = down_limit; i >= up_limit; --i) {
                        result[i][current_col] = index++;
                    }
                    ++left_limit;
                    direction = RIGHT;
                    break;
                default:
                    System.out.println("Never be here");
                    break;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] t = sol.generateMatrix(5);
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                System.out.printf("%3d ", t[i][j]);
            }
            System.out.println();
        }
    }
}


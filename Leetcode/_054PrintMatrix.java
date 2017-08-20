import java.util.ArrayList;
import java.util.List;

class Solution {
    // 螺旋矩阵，和PAT上的那个不太一样
    // 这个是给出矩阵让你把数字取出来
    // PAT那个给你数据自己建一个矩阵，比这个难多了
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return result;
        // 四个方向
        final int right = 1, down = 2, left = 3, up = 4;
        // 方向
        int position = right;
        // 总体数字个数
        int sum = matrix.length * matrix[0].length;
        // 上下左右的限制
        int up_limit = 0, down_limit = matrix.length - 1, left_limit = 0, right_limit = matrix[0].length - 1;
        // 没有用的两个变量
        int row_index = 0, col_index = 0;
        while (sum > 0) {
            // 进行状态切换等操作
            switch (position) {
                case right:
                    col_index = up_limit;
                    while (col_index <= right_limit) {
                        result.add(matrix[up_limit][col_index++]);
                        sum--;
                    }
                    up_limit++;
                    position = down;
                    break;
                case down:
                    row_index = up_limit;
                    while (row_index <= down_limit) {
                        result.add(matrix[row_index++][right_limit]);
                        sum--;
                    }
                    position = left;
                    right_limit--;
                    break;
                case left:
                    col_index = right_limit;
                    while (col_index >= left_limit) {
                        result.add(matrix[down_limit][col_index--]);
                        sum--;
                    }
                    position = up;
                    down_limit--;
                    break;
                case up:
                    row_index = down_limit;
                    while (row_index >= up_limit) {
                        result.add(matrix[row_index--][left_limit]);
                        sum--;
                    }
                    position = right;
                    left_limit++;
                    break;
            }
        }
        // 返回结果
        return result;
    }

    public static void main(String[] args) {
        int[][] test = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};
        Solution sol = new Solution();
        List<Integer> result = sol.spiralOrder(test);
        System.out.println(result);
        System.out.println("[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]");
    }
}


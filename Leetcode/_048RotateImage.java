class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) return;
        int len = matrix.length;
        int[] temp = new int[len];
        int depth = 0;
        for (int i = len / 2; i >= 1; i--) {
            // 交换四个角落
            int limit = len - depth - 1;
            int t = matrix[depth][depth];
            matrix[depth][depth] = matrix[limit][depth];
            matrix[limit][depth] = matrix[limit][limit];
            matrix[limit][limit] = matrix[depth][limit];
            matrix[depth][limit] = t;
            // 没问题
            for (int j = depth + 1; j < limit; j++) {
                temp[j] = matrix[depth][j];
            }
            // 复制左到上，OK
            // limit = 2
            for (int j = limit - 1; j > depth; j--) {
                matrix[depth][len - j - 1] = matrix[j][depth];
            }
            // 复制下到左，OK
            for (int j = limit - 1; j > depth; j--) {
                matrix[j][depth] = matrix[limit][j];
            }
            // 复制右到下，
            // depth = 0，limit = 2
            for (int j = depth + 1; j < limit; j++) {
                matrix[limit][len - j - 1] = matrix[j][limit];
            }
            // 上到右
            for (int j = depth + 1; j < limit; j++) {
                matrix[j][limit] = temp[j];
            }
            ++depth;
        }
    }

    public static void main(String[] args) {
        int[][] test = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {1, 2, 3, 4},
                {5, 6, 7, 8}};
        Solution sol = new Solution();
        sol.rotate(test);
        for (int i = 0; i < test.length; i++) {
            for (int j = 0; j < test.length; j++) {
                System.out.print(test[i][j]);
            }
            System.out.println();
        }
    }
}

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // 0,0是1的直接放弃
        if (obstacleGrid == null || obstacleGrid[0][0] == 1) return 0;
        final int cols = obstacleGrid[0].length, rows = obstacleGrid.length;

        // 这里处理了0,0
        for (int i = 0; i < cols; i++) {
            if (obstacleGrid[0][i] == 1) {
                while (i < cols) obstacleGrid[0][i++] = 0;
            } else {
                obstacleGrid[0][i] = 1;
            }
        }

        // 不需要再次处理0,0
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0] == 1) {
                while (i < rows) obstacleGrid[i++][0] = 0;
            } else {
                obstacleGrid[i][0] = 1;
            }
        }

        // 和上一个unique path一样，遍历就行了
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }
        if (cols == 1) {
//            return obstacleGrid[rows - 1][]
        }
        return obstacleGrid[rows - 1][cols - 1];
    }

    public static void main(String[] args) {

        Solution sol = new Solution();
        int[][] test = {
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0}
        };
        System.out.println(sol.uniquePathsWithObstacles(test));

    }
}

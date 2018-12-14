#include <stdio.h>
#include <limits.h>


int matrix[105][105];

int main() {
    int m, n;
    int max_idx, sum;

    while (~scanf("%d %d", &m, &n)) {
        // 输入数据啊
        for (int i = 0; i < m; ++i) {
            max_idx = 0;
            sum = 0;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j]);
                sum += matrix[i][j];
                if (matrix[i][j] > matrix[i][max_idx]) {
                    max_idx = j;
                }
            }
            matrix[i][max_idx] = sum;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d%c", matrix[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
    }
    
    
    return 0;
}
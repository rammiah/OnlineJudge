#include <cstdio>
#include <map>

using namespace std;

char matrix[250][250];
int dp[260][260];

inline int min(int a, int b, int c) {
    return a > b ? b
                 : a > c ? c : a;
}

int main() {
    // freopen("044.txt", "r", stdin);
    int row;
    scanf("%d", &row);
    char buff[260];
    for (int i = 0; i < row; ++i) {
        scanf("%s", buff);
        for (int j = 0; j < row; ++j) {
            matrix[i][j] = buff[j] - '0';
        }
    }
    // 填充第一行和第一列
    for (int i = 0; i < row; ++i) {
        dp[0][i] = matrix[0][i];
        dp[i][0] = matrix[i][0];
    }
    int max = 0;
    int sum[260] = {0};
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < row; ++j) {
            // 可以向下拓展
            if (matrix[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
            if (dp[i][j] >= 2) {
                sum[dp[i][j]]++;
            }
            max = max > dp[i][j] ? max : dp[i][j];
        }
    }
    // 得到一个4需要左边是3，上边是3，左上是3，这3个都是被计算了的，多的一个就是以当前为顶点的一个，加一即可
    // 总结出来的规律
    for (int i = max - 1; i >= 2; --i) {
        sum[i] = sum[i + 1] + sum[i];
    }
    // 输出就行了
    for (int i = 2; i <= max; ++i) {
        printf("%d %d\n", i, sum[i]);
    }
    
    return 0;
}
#include <cstdio>

using namespace std;

// 不能使用ull，只有任其溢出才是对的，这答案真恶心
int dp[105][105];

int main() {
    // freopen("063.txt", "r", stdin);
    int col, row;
    for (int i = 0; i < 105; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < 105; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 105; ++i) {
        for (int j = 1; j < 105; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    while (scanf("%d %d", &row, &col) != EOF) {
       printf("%d\n", dp[row - 1][col - 1]);
    }


    return 0;
}
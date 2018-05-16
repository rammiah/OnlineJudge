#include <cstdio>

int dp[51];

int main() {
    int cnt;
    scanf("%d", &cnt);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= cnt; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d\n", dp[cnt]);

    return 0;
}
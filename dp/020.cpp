#include <cstdio>
#include <cstring>

int nums[101];
unsigned int dp[101];

void up_min(unsigned int &a, unsigned int b) {
    a = a < b ? a : b;
}

int main() {
    // freopen("020.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &nums[i]);
    }

    dp[0] = 0;
    for (int i = 0; i < cnt; ++i) {
        for (int j = i + 1; j <= i + nums[i] && j < cnt; ++j) {
            up_min(dp[j], dp[i] + 1);
        }
    }

    printf("%u\n", dp[cnt - 1]);

    return 0;
}
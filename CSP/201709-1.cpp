#include <cstdio>
#include <map>

int dp[100];

void update(int &a, int b) {
    a = a > b ? a : b;
}

int main() {
    using std::map;
    int money;
    scanf("%d", &money);
    int m[6] = {0, 1, 2, 4, 5, 7};
    money /= 10;
    dp[0] = 0;
    // 简单dp
    for (int i = 1; i <= money; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= 5; ++j) {
            if (i >= j) {
                update(dp[i], dp[i - j] + m[j]);
            }
        }
    }

    printf("%d\n", dp[money]);

    return 0;
}

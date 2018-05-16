#include <cstdio>

// 质数保证乘积和加减模同余
#define MOD 9901

// 一维人数，二维代数
int dp[201][101];

int main() {
    // freopen("029.txt", "r", stdin);
    // 这个简单一点
    int num, gen;
    // 获取人的数目和代数
    scanf("%d %d", &num, &gen);
    dp[1][1] = 1;
    
    // i表示人数
    // 每次加2，只有奇数才可能是树
    if (num&1) {
        for (int i = 3; i <= num; i += 2) {
            // j是子孙代数
            for (int j = 1; j <= gen; ++j) {
                // 填充dp[num][gen]
                // 又来一个循环
                // 分边讨论
                // 左侧为j代，右侧为1~j - 1代
                // 左侧人数从1到i - 2(右侧不能为0)
                // dp[left_p][left_gten]
                int sum = 0;
                for (int left_p = 1; left_p <= i - 2; left_p += 2) {
                    // 计算右侧所有可能的当i - left_p - 1人时1~j - 1代
                    int gen_sum = 0;
                    int right_p = i - left_p - 1;
                    if (right_p >= 1) {
                        for (int right_g = 1; right_g <= j - 1; ++right_g) {
                            gen_sum += dp[right_p][right_g] % MOD;
                        }
                    }
                    sum += dp[left_p][j - 1] * gen_sum % MOD;
                }
                // 左侧为1~j - 2代,右侧为j - 1代
                for (int right_p = 1; right_p <= i - 2; right_p += 2) {
                    int gen_sum = 0;
                    int left_p = i - right_p - 1;
                    if (left_p >= 1) {
                        for (int left_g = 1; left_g <= j - 2; ++left_g) {
                            gen_sum += dp[left_p][left_g] % MOD;
                        }
                    }
                    sum += dp[right_p][j - 1] * gen_sum % MOD;
                }
                dp[i][j] = sum % MOD;
                // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
    }
    

    printf("%d\n", dp[num][gen]);
    

    return 0;
}
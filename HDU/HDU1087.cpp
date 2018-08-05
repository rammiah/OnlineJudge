#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define MAXN 1005

using namespace std;

int nums[MAXN];
int dp[MAXN];

void up_max(int &a, int b) {
    a = a > b ? a : b;
}

int main() {
    // 最大递增子序列
    // freopen("data.txt", "r", stdin);
    int cnt, max;
    cin >> cnt;
    while (cnt != 0) {
        // 输入数字，不超过1k个
        max = 0;
        for (int i = 0; i < cnt; ++i) {
            cin >> nums[i];
            // 在此可以直接计算
            dp[i] = nums[i];
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    up_max(dp[i], dp[j] + nums[i]);
                    
                }
            }
            up_max(max, dp[i]);
        }
        cout << max << "\n";
        cin >> cnt;
    }

    return 0;
}
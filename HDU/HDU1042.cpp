#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAXN 40000

using namespace std;

int nums[MAXN];

int main() {
    int n;
    int carry = 0, max_idx = 0;
    while (~scanf("%d", &n)) {
        // 计算n!
        memset(nums, 0, sizeof(nums));
        // 开始计算吧
        nums[0] = 1;
        max_idx = 0;
        for (int i = 1; i <= n; ++i) {
            // 记录一下吧
            for (int j = 0; j <= max_idx; ++j) {
                carry = i * nums[j] + carry;
                nums[j] = carry % 10;
                carry /= 10;
            }
            // 每乘一次都要计算max_idx需要增长到哪里
            while (carry) {
                nums[++max_idx] = carry % 10;
                carry /= 10;
            }
        }
        // 开始输出
        for (int i = max_idx; i >= 0; --i) {
            printf("%d", nums[i]);
        }
        printf("\n");
    }


    return 0;
}
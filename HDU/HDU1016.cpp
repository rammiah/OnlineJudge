#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAXN 45

bool is_prime[MAXN] = {false, false};
void init() {
    for (int i = 2; i < MAXN; ++i) {
        is_prime[i] = true;
    }
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            int t = i << 1;
            while (t < MAXN) {
                is_prime[t] = false;
                t += i;
            }
        }
    }
}

bool used[25];
int mod;
vector<int> result;

// 不知道dfs是否可以
void dfs(int idx) {
    // 最后一个数字
    if (idx == mod - 1) {
        // 肯定只剩一个了
        for (int i = 2; i <= mod; ++i) {
            if (!used[i]) {
                if (is_prime[i + 1] && is_prime[i + result[idx - 1]]) {
                    result[idx] = i;
                    // 输出
                    for (int i = 0; i < mod; ++i) {
                        printf("%d%c", result[i], (i == mod - 1 ? '\n' : ' '));
                    }
                }
                break;
            }
        }
        return;
    }
    for (int i = 2; i <= mod; ++i) {
        if (is_prime[i + result[idx - 1]] && !used[i]) {
            used[i] = true;
            result[idx] = i;
            dfs(idx + 1);
            used[i] = false;
        }
    }
}

int main() {
    init();
    int id = 1;
    while (scanf("%d", &mod) != EOF) {
        printf("Case %d:\n", id++);
        if (mod > 1 && mod %2 == 1) {
            // 没有
            printf("\n");
            continue;
        }
        else if (mod == 1) {
            printf("1\n\n");
            continue;
        }
        memset(used, 0, sizeof(used));
        result.resize(mod, 0);
        result[0] = 1;
        used[1] = true;
        dfs(1);
        printf("\n");
    }

    return 0;
}
/*
8
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/
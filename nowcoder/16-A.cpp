#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using ull = unsigned long long;
ull MOD = (int)1E9 + 7;

int prime_cnt = 0;
int primes[2000];
bool is_prime[2005];
int up[2005] = { 0, };
int down[2005] = { 0, };

// 素数打表
void init() {
    for (int i = 2; i < 2005; ++i) {
        is_prime[i] = true;
    }
    is_prime[2] = true;
    for (int i = 2; i < 2005; ++i) {
        if (is_prime[i]) {
            primes[prime_cnt++] = i;
            int t = i << 1;
            while (t < 2005) {
                is_prime[t] = false;
                t += i;
            }
        }
    }
}

// 数字分解
void fenjie(int num, int *arr) {
    int t = num;
    int idx = 0;
    while (t > 1) {
        if (t % primes[idx] == 0) {
            while (t % primes[idx] == 0 && t > 1) {
                arr[idx]++;
                t /= primes[idx];
            }
        }
        idx++;
    }
}

// 阶乘分解
void jiechengfenjie(int num, int *arr) {
    for (int i = 2; i <= num; ++i) {
        // 分解i
        fenjie(i, arr);
    }
}

int main() {
    init();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    // 质因数分解它
    jiechengfenjie(sum, up);
    jiechengfenjie(a, down);
    jiechengfenjie(b, down);
    jiechengfenjie(c, down);
    jiechengfenjie(d, down);
    int result = 1;
    for (int i = 0; i < prime_cnt; ++i) {
        up[i] -= down[i];
        while (up[i] > 0) {
            result = result * primes[i] % MOD;
            up[i]--;
        }
    }

    std::cout << result << "\n";

    return 0;
}
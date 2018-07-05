#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 20005

using namespace std;
using ll = long long;

// 最差O(n^2)，O(nlog(n))还行

int dp[MAXN][MAXN];

string str;

int low_bit(int a) {
    
}

int get_f(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (dp[l][r] == -1) {
        // 计算一下dp[l][r]
        if (r - low_bit(r) >= l) {
            dp[l][r] = get_f(l, r - low_bit(r)) + 1;
        } else {
            dp[l][r] = get_f(l, r - 1) + 1;
        }
    }
    return dp[l][r];
}

int main() {
    cin >> str;
    // 开始dp，推导dp方程
    // 全部设置为-1
    memset(dp, 1, sizeof(dp));


    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll fact[1005];

// 初始化阶乘
void init() {
	fact[0] = 1;
	for (int i = 1; i < 1005; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
}

// 快速幂
ll fast_pow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
// 真是差了个字母就错了
ll get_c(ll m, ll n) {
	// 使用模逆元获取组合数
	return fact[m] * fast_pow(fact[n], MOD - 2) % MOD * fast_pow(fact[m - n], MOD - 2) % MOD;
}

ll get_ans(ll num) {
	ll result = 0;
	ll n = num - 1;

	for (ll i = 0; i <= n / 2; i += 2) {
		result = (result + get_c(n, i) * get_c(n - i, i) % MOD) % MOD;
	}

	return result;
}

int main() {
	init();
	ll n;
	cin >> n;
	cout << get_ans(n) << "\n";

	return 0;
}
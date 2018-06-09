#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MAXN 2000010
using ull = unsigned long long;
const ull MOD = 998244353;

using namespace std;
ull fac[MAXN];

ull fast_pow(ull a, ull b) {
	ull res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

ull C(ull n) {
	return fac[2 * n] * fast_pow(fac[n], MOD - 2) % MOD * fast_pow(fac[n], MOD - 2) % MOD;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}

	long long n;
	scanf("%lld", &n);
	ull ans = 0;
	for (ull i = 1; i <= n; ++i) {
		ans = (ans + C(i)) % MOD;
	}
	printf("%llu\n", n >= 1 ? ans : 0);

	return 0;
}

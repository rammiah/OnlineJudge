#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#define MAXN 100000

using namespace std;
using ll = long long;

bool is_prime[MAXN];
int primes[MAXN];
int prime_cnt = 0;

void init() {
	fill(is_prime + 2, is_prime + MAXN, true);
	for (int i = 2; i < MAXN; ++i) {
		if (is_prime[i]) {
			primes[prime_cnt++] = i;
			int t = i << 1;
			while (t < MAXN) {
				is_prime[t] = false;
				t += i;
			}
		}
	}
}

int get_pfactor_cnt(int num) {
	ll n = num;
	int result = 0;
	int root = sqrt(n);
	for (int i = 0; primes[i] <= root; ++i) {
		if (n % primes[i] == 0) {
			while (n % primes[i] == 0) {
				++result;
				n /= primes[i];
			}
		}
	}

	if (n != 1) {
		result++;
	}
	return result;
}

int main() {
	init();
	int n;
	while (cin >> n) {
		cout << get_pfactor_cnt(n) << "\n";
	}


	return 0;
}

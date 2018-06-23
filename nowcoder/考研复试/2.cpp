#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int get_factor_cnt(int num) {
	ll n = num;
	int result = 0;
	ll i;
	for (i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			result += 2;
		}
	}
	if (i * i == n) {
		result--;
	}

	return result;
}

int main() {
	int cnt, num;
	while (cin >> cnt) {
		for (int i = 0; i < cnt; ++i) {
			cin >> num;
			cout << get_factor_cnt(num) << "\n";
		}
	}

	return 0;
}

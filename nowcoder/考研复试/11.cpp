#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll get_ans(ll a, ll b) {
	ll suma = 0;
	ll sumb = 0;
	while (a) {
		suma += a % 10;
		a /= 10;
	}
	while (b) {
		sumb += b % 10;
		b /= 10;
	}

	return suma * sumb;
}

int main() {
	ll a, b;
	while (cin >> a >> b) {
		// 实质上就是个位数相加，最后相乘
		cout << get_ans(abs(a), abs(b));
	}


	return 0;
}
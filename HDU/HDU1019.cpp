#include <cstdio>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int T, cnt;
	// 我估计没问题
	ll result, num;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &cnt);
		result = 1;
		while (cnt--) {
			scanf("%lld", &num);
			result = result / gcd(result, num) * num;
		}
		printf("%lld\n", result);
	}
	
	return 0;
}

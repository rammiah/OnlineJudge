#include <cstdio>
#define MAXK 1001

using namespace std;
double an[MAXK];

int main(void) {
	// 多项式求和嘛，简单
	int cnt;
	double a;
	int ex;
	for (int i = 0; i < MAXK; ++i) {
		an[i] = 0;
	}
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d %lf", &ex, &a);
		an[ex] += a;
	}
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d %lf", &ex, &a);
		an[ex] += a;
	}
	cnt = 0;
	for (int i = 0; i < MAXK; ++i) {
		if (an[i] != 0) {
			++cnt;
		}
	}
	cnt == 0 ? printf("0\n") :  printf("%d ", cnt);
	for (int i = MAXK; i >= 0; --i) {
		if (an[i] != 0) {
			if (--cnt) {
				printf("%d %.1f ", i, an[i]);
			} else {
				printf("%d %.1f\n", i, an[i]);
				break;
			}
		}
	}

	return 0;
}
#include <cstdio>
using namespace std;
int dp[10000], start[10000], end, arr[10000];
int main() {
	int cnt = 0;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i)scanf("%d", &arr[i]);
	int max = -1, maxIdx = 0;
	dp[0] = start[0] = end = arr[0];
	for (int i = 0; i < cnt; ++i) {
		if (dp[i - 1] > 0) {
			dp[i] = dp[i - 1] + arr[i];
			start[i] = start[i - 1];
		} else {
			dp[i] = arr[i];
			start[i] = dp[i];
		}
		if (dp[i] > max) {
			max = dp[i];
			end = arr[i];
			maxIdx = i;
		}
	}
	max >=0 ? printf("%d %d %d\n", max, start[maxIdx], end) : printf("0 %d %d\n", arr[0], arr[cnt - 1]);
	return 0;
}
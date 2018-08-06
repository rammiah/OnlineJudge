#include <cstdio>

using namespace std;

int nums[10005];
int starts[10005];
int dp[10005];

int main() {
	int cnt;
	int max_end = 0, max_val = -1;
	scanf("%d", &cnt);
	while (cnt != 0) {
		for (int i = 0; i < cnt; ++i) {
			scanf("%d", &nums[i]);
		}
		dp[0] = nums[0];
		starts[0] = nums[0];
		max_val = nums[0];
		max_end = 0;
		for (int i = 1; i < cnt; ++i) {
			if (dp[i - 1] > 0) {
				dp[i] = dp[i - 1] + nums[i];
				starts[i] = starts[i - 1];
			} else {
				dp[i] = nums[i];
				starts[i] = nums[i];
			}
			// max change
			if (dp[i] > max_val) {
				max_val = dp[i];
				max_end = i;
			}
		}
		if (max_val >= 0) {
			printf("%d %d %d\n", max_val, starts[max_end], nums[max_end]);
		} else {
			printf("0 %d %d\n", nums[0], nums[cnt - 1]);
		}
		
		scanf("%d", &cnt);
	}
	
	return 0;
}
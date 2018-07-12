#define MAXN 1005
int dp[MAXN];

class Solution {
public:
	int minSteps(int n) {
		for (int i = 0; i < MAXN; i++) {
			dp[i] = i;
		}
		dp[1] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i * 2; j <= n; j += i) {
				dp[j] = min(dp[i] + j / i, dp[j]);
			}
		}

		return dp[n];
	}
};

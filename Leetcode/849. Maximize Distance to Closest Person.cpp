void up_min(int &a, int b) {
    a = a > b ? b : a;
}

void up_max(int &a, int b) {
    a = a > b ? a : b;
}

int dp[20005];

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		// 寻找最长0串
        memset(dp, 0, sizeof(dp));
		int max_len = 0;
		int left, right;
		int size = seats.size();
		// 先找开头和结尾最长串
		for (int i = 0; i < size; i++) {
			if (seats[i] == 1) {
				left = i + 1;
				break;
			}
			up_max(max_len, i + 1);
		}
		for (int i = size - 1; i >= 0; --i) {
			if (seats[i] == 1) {
				right = i - 1;
				break;
			}
			up_max(max_len, size - i);
		}
		if (max_len >= size / 2) {
			return max_len;
		}

		for (int i = left; i <= right; ++i) {
			if (seats[i] == 0) {
				dp[i] = dp[i - 1] + 1;
				up_max(max_len, (dp[i] + 1) / 2);
			}
		}
		return max_len;
	}
};
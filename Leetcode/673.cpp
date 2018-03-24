int dp[2000];
//int counts[2000];
int record[2000];
// 2 2 2 2 2
// 5个
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int cnt = 0;
        int max_len = 0;
        record[0] = 1;
        dp[0] = 1;
        for (int i = 1; i < size; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        // 突然相通
                        record[i] = record[j];
                        if (dp[i] > max_len) {
                            max_len = dp[i];
                        }
                    } else if (dp[j] + 1 == dp[i]) {
                        record[i] += record[j];
                    }
                }
            }
            if (dp[i] == 1) {
                record[i] = 1;
            }
        }
        cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (dp[i] == max_len) {
                cnt += record[i];
            }
        }
        return cnt;
    }
};
int dp[20005];

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0, max = 0;
        std::memset(dp, 0, sizeof(dp));
        std::sort(nums.begin(), nums.end());
        for (int num : nums) {
            sum += num;
            max = std::max(max, num);
        }

        if (sum % 2 == 1 || max > sum / 2) {
            return false;
        }
        // 求是否存在sum的就行了
        sum /= 2;

        dp[0] = 1;
        for (int num : nums) {
            for (int j = sum; j >= num; --j) {
                if (dp[j - num] == 1) {
                    dp[j] = 1;
                }
            }
        }

        return dp[sum] == 1;
    }
};
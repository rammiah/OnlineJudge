int dp[10000];

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int size = nums.size();
        dp[0] = 1;
        int m = 1;
        // 最简单的dp
        for (int i = 1; i < size; ++i) {
            dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1;
            m = max(dp[i], m);
        }
        return m;
    }
};
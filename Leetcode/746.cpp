class Solution {
int dp[1002];

public:
    // 低级dp
    int minCostClimbingStairs(vector<int>& cost) {
        dp[0] = cost[0];
        dp[1] = cost[1];
        int size = cost.size();
        for (int i = 2; i < size; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[size - 1], dp[size - 2]);     
    }
};
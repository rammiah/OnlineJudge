int dp[100005];

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> more_gas(2 * gas.size());
        for (int i = 0; i < cost.size(); ++i) {
            more_gas[i] = more_gas[i + cost.size()] = gas[i] - cost[i];
        }
        memset(dp, 0, sizeof(dp));

        int start = 0, old_start = 0;
        // 计算是否存在最大子数组和，记录起点
        dp[0] = more_gas[0];
        int max_sum = dp[0];
        for (int i = 1; i < cost.size() * 2; ++i) {
            if (dp[i - 1] > 0) {
                dp[i] = more_gas[i] + dp[i - 1];
            }
            else {
                dp[i] = more_gas[i];
                old_start = i;
            }
            if (dp[i] > max_sum) {
                max_sum = dp[i];
                start = old_start;
            }
        }
        int sum = 0;
        // 从最大子数组起点开始走一圈看看
        for (int i = start; i < start + cost.size(); ++i) {
            sum += more_gas[i];
            if (sum < 0) {
                start = -1;
                break;
            }
        }

        return start;
    }
};
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAXN 5005

int dp[505][MAXN];

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) {
            return amount == 0 ? 1 : 0;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= amount / coins[0]; ++i) {
            dp[0][i * coins[0]] = 1;
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i]) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }

        return dp[coins.size() - 1][amount];
    }
};


int main() {
    Solution sol;
    vector<int> coins {1,2, 5};
    cout << sol.change(5, coins);

    return 0;
}

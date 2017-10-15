#include<string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] < '1' || s[0] > '9') {
            return 0;
        }
        vector<int>dp(s.size() + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (!isdigit(s[i])) {
                return 0;
            }
            int v = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (v <= 26 && v >= 10) {
                dp[i + 1] += dp[i - 1];
            }
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
            if (dp[i + 1] == 0) return 0;
        }

        return dp[s.size()];
    }
};
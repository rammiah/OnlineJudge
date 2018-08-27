#define MAXN 1000
int helper[MAXN][MAXN];
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        memset(helper, 0, sizeof(helper));
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            helper[i][0] = matrix[i][0] - '0';
            result = max(result, helper[i][0]);
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            helper[0][i] = matrix[0][i] - '0';
            result = max(result, helper[0][i]);
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    helper[i][j] = min(helper[i-1][j - 1], min(helper[i][j - 1], helper[i - 1][j])) + 1;
                    result = max(helper[i][j], result);
                }
            }
        }
        return result * result;
    }
};
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;
class Solution {
    ull F[21][21], S[21][21];
public:
    Solution() {
        for (int i = 0; i < 21; ++i) {
            for (int j = 0; j < 21; ++j) {
                F[i][j] = S[i][j] = 0;
            }
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        // 参考博客https://blog.csdn.net/qwe_lingkun/article/details/47305035
        // 先拿的的人肯定是拿第一个或者第最后一个
        int size = nums.size();
        // 拿第一个
        F[0][0] = nums[0];
        // 拿最后一个
        F[size - 1][size - 1] = nums[size - 1]; 
        for (int j = 1; j < size; ++j) {
            for (int i = size - 2; i >= 0; --i) {
                if (i <= j) {
                    F[i][j] = max(nums[i] + S[i + 1][j], nums[j] + S[i][j - 1]);
                    S[i][j] = min(F[i + 1][j], F[i][j - 1]);
                } else {
                    F[i][j] = S[i][j] = 0;
                }
            }
        }

        return F[0][size - 1] >= S[0][size - 1];
    }
};

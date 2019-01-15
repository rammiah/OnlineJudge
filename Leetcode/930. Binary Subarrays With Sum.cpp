class Solution {
public:
    int numSubarraysWithSum(const vector<int> &A, int S) {
        // 和为s的子数组的个数
        int res = 0;
        vector<int> idxs;
        idxs.push_back(-1);
        int idx = 0;
        // 10101
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 1) {
                idxs.push_back(i);
            }
        }
        idxs.push_back(A.size());
        // 0的情况需要特殊处理
        if (S == 0) {
            // C(N, 2)
            for (int i = 1; i < idxs.size(); ++i) {
                res += (idxs[i] - idxs[i - 1]) * ((idxs[i] - idxs[i - 1]) - 1) / 2;
            }
        } else {
            // 参考乘法原理
            for (int i = 1; i < idxs.size() - S; ++i) {
                res += (idxs[i] - idxs[i - 1]) * (idxs[i + S] - idxs[i + S - 1]);
            }
        }

        return res;
    }
};
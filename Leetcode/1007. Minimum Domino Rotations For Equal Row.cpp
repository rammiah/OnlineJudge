class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // 不知道全部是多少的话一个一个检测吧
        int res = INT_MAX;
        for (int i = 1; i <= 6; ++i) {
            int a_cnt = 0, b_cnt = 0;
            for (int j = 0; j < A.size(); ++j) {
                if (A[j] != i && B[j] != i) {
                    a_cnt = b_cnt = INT_MAX;
                    break;
                } else if (B[j] == i && A[j] != i) {
                    ++a_cnt;
                } else if (B[j] != i && A[j] == i) {
                    ++b_cnt;
                }
            }
            res = min(a_cnt, res);
            res = min(b_cnt, res);
        }
        return res == INT_MAX ? -1 : res;
    }
};

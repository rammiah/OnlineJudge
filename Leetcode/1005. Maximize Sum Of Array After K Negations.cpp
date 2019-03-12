class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        // 最小的在前面
        int neg_cnt = 0;
        int min_val = INT_MAX;
        for (auto &a : A) {
            if (a < 0 && K > 0) {
                --K;
                a = -a;
                min_val = min(a, min_val);
                if (K == 0) {
                    break;
                }
            } else if (a == 0 && K > 0) {
                min_val = 0;
                K = 0;
                break;
            } else if (a > 0) {
                min_val = min(a, min_val);
                break;
            }
            // min_val = min(a, min_val);
        }
        int sum = 0;
        for (auto &val :  A) {
            sum += val;
        }
        if (K & 1) {
            sum -= 2 * min_val;
        }
        return sum;
    }
};
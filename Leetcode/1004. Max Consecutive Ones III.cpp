class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // 可能使用回溯法吧
        int res = K; // 最长要有K个吧
        const int len = A.size();
        for (int i = 0; i < len;) {
            while (i < len && A[i] == 0) {
                i++;
            }
            // 是1, 假设从这里开始一直向后补充1
            int k = K;
            for (int j = i + 1; j < len; ++j) {
                if (A[j] == 0) {
                    if (k == 0) {
                        // 到此为止
                        res = max(res, j - i);
                        break;
                    } else {
                        --k;
                        res = max(res, j + 1 - i);
                        if (j == len - 1 && k > 0) {
                            res = max(res, j + 1 + k - i);
                        }
                    }
                } else {
                    if (j == len - 1 && k > 0) {
                        // 没用完啊
                        res = max(res, j + 1 + k - i);
                        break;
                    }
                    res = max(res, j + 1 - i);
                }
            }
            ++i;
            while (i < len && A[i] == 1) {
                ++i;
            }
        }
        
        return min(res, len);
    }
};

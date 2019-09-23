int line0[10000], line1[10000];
class Solution {
public:
    int findLength(const std::vector<int> &A, const std::vector<int> &B) {
        // 最长公共子串的长度
        int *line0_ptr = line0, *line1_ptr = line1;
        int res = 0;
        // 下面开始第二行的
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    if (i == 0) {
                        line1_ptr[j] = 1;
                    } else {
                        if (j == 0) {
                            line1_ptr[j] = 1;
                        } else {
                            line1_ptr[j] = line0_ptr[j - 1] + 1;
                            res = std::max(res, line1_ptr[j]);
                        }
                    }
                } else {
                    line1_ptr[j] = 0;
                }
            }
            std::swap(line0_ptr, line1_ptr);
        }

        return res;
    }
};

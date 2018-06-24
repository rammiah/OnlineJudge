class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        // 交换两个字符使得AB相同
        // 检测A和B中不同的字符位置个数
        int diff_cnt = 0;
        int idxs[20005] = { 0, 0 };
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                idxs[diff_cnt++] = i;

            }
        }
        if (diff_cnt == 0) {
            // 没有不同
            // 看A里是否有相同的字符
            map<char, bool> m;
            for (auto &ch : A) {
                if (m[ch]) {
                    return true;
                }
                else {
                    m[ch] = true;
                }
            }
            return false;
        }
        else if (diff_cnt != 2) {
            return false;
        }
        swap(A[idxs[0]], A[idxs[1]]);
        return A == B;
    }
};
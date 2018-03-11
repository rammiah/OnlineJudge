
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        ull length = A.length();
        int a_nums[100], b_nums[100];
        for (int i = 0; i < length; ++i) {
            a_nums[i] = A[i];
            b_nums[i] = B[i];
        }

        // 旋转判断
        for (int i = 0; i < length; ++i) {
            bool same = true;
            for (int j = 0; same && j < length; ++j) {
                if (A[j] != B[(j + i) % length]) {
                    same = false;
                }
            }

            if (same) {
                return true;
            }
        }

        return false;
    }
};

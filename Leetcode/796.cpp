using ull = unsigned long long;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        ull length = A.length();
        // 旋转判断
        for (int i = 0; i < length; ++i) {
            bool same = true;
            for (int j = 0; same && j < length; ++j) {
                if (A[j] != B[(j + i) % length]) {
                    same = false;
                }
            }
            // 相同返回true
            if (same) {
                return true;
            }
        }
        // 移位全部试探失败
        return false;
    }
};

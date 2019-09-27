class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        // 从后向前加吧，需要考虑最前面是否需要进位直接开一个新的vector存储结果，最后reverse一下
        int idx = A.size() - 1;
        while (idx >= 0 || K > 0) {
            // 直接加，不要怂
            if (idx >= 0) {
                K += A[idx];
            } else {
                A.insert(A.begin(), K % 10);
                K /= 10;
                continue;
            }
            A[idx] = K % 10;
            --idx;
            K /= 10;
        }
        return A;
    }
};

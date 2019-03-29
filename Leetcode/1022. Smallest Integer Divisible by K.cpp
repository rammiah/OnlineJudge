class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        // 1的串，可被K整除
        int32_t res = 1;
        int32_t num = 1;
        // 使用鸽巢原理证明
        for (int i = 0; i <= K; ++i) {
            if (num % K == 0) {
                return res;
            }
            num = (num * 10 + 1) % K;
            res++;
        }
        
        return -1;
    }
};

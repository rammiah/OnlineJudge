class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        // 虽然很没意思，但是还是有时间学习一下位运算吧
        long t = (long)dividend / divisor;
        if (t > INT_MAX) {
            return INT_MAX;
        }
        return dividend / divisor;
    }
};
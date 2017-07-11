class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        // 这个数是3的在int里最大的幂值，用py算的，只要是3的幂就一定能整除
        return 3486784401 % n == 0;
    }
};
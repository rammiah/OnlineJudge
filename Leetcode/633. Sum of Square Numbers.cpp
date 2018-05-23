class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        int sum = a * a + b * b;
        while (a <= b) {
            sum = a * a + b * b;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
};
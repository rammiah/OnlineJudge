_357. Count Numbers with Unique Digits.java
class Solution {
    private static final int[] dp = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 5611771};
    // 直接python计算所有有效的
    public int countNumbersWithUniqueDigits(int n) {
        if (n >= 11) {
            return 0;
        }

        return dp[n];
    }
}
public class Solution {
    public static void main(String[] args) {
        System.out.println("Hello java");
    }
    // 动态规划，分析状态转移
    public int longestValidParentheses(String s) {
        int size = s.length();
        int[] DP = new int[size + 1];
        int left = 0, longest = 0;
        for (int i = 0; i < size; ++i) {
            if (s.charAt(i) == '(') {
                left++;
            } else if (s.charAt(i) == ')' && left > 0) {
                DP[i + 1] = DP[i] + 2;
                DP[i + 1] += DP[i + 1 - DP[i + 1]];
                left--;
            }
            longest = DP[i + 1] > longest ? DP[i + 1] : longest;
        }

        return longest;
    }
}

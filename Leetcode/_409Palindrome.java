// 寻找可以组成的最长的回文字符串
public class _409Palindrome {
    public int longestPalindrome(String s) {
        // 记录字母出现次数
        int[] charCount = new int[256];
        // 转换成字符串，便于处理
        char[] chars = s.toCharArray();
        // 查数
        for (char c : chars) {
            ++charCount[c];
        }
        // 偶数一定能填进去，奇数的记录一下，有奇数只能放count - 1个，最后加一个中间的可以
        boolean haveOdd = false;
        int result = 0;
        // 求和开始
        for (int i : charCount) {
            // 判断奇数
            if (i % 2 == 1) {
                haveOdd = true;
                // 只能放这么多
                result += i - 1;
            } else {
                result += i;
            }
        }
        // 有奇数的加个1
        if (haveOdd) {
            result++;
        }

        return result;
    }
}

package Leetcode;

/**
 * Created by yaning on 17-6-3.
 */
public class _334ReverseString {
    static class Solution {
        // 简单到不忍直视
        //
        public String reverseString(String s) {
            // 调用系统函数
            StringBuilder builder = new StringBuilder(s);
            return builder.reverse().toString();
        }
        // 更高效的一种方法
        // 看到答案里用栈做的，脑子是进水了吗？？？不知道进出栈多耗时间吗
        public String best(String s) {
            char[] chars = s.toCharArray();
            char ch;
            int start = 0;
            int end = s.length() - 1;
            while (start < end) {
                ch = chars[start];
                chars[start] = chars[end];
                chars[end] = ch;
                start++;
                end--;
            }
            return String.valueOf(chars);
        }
    }
}

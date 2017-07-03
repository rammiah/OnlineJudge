package Leetcode;

/**
 * Created by yaning on 17-6-6.
 */
public class _014LongPrefixStr {
    public static void main(String[] args) {
        String[] strs = { "bbb", "bbbb" };

        Solution sol = new Solution();

        System.out.println(sol.longestCommonPrefix(strs));
    }

    static class Solution {
        public String longestCommonPrefix(String[] strs) {
            if (strs == null || strs.length == 0) {
                return "";
            }
            // 初始化一个字符串，直接用strs[0]初始化。
            String str = strs[0];
            int len = str.length();
            for (int i = 1; i < strs.length; i++) {
                // startsWith可能比indexOf好一点，
                // 毕竟不需要去考虑后面的字符串了
                while (!strs[i].startsWith(str)) {
                    str = str.substring(0, --len);
                }
            }
            // 结束
            return str;
        }
    }
}

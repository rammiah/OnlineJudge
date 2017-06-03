package Leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by yaning on 17-6-3.
 */
public class _006ZigZag {

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.convert("PAYPALISHIRING", 3));
        System.out.println("PAHNAPLSIIGYIR");
    }

    static class Solution {
        // 算法很简单，就是按照顺序填入事先准备的数组，最后一同取出来
        public String convert(String s, int numRows) {
            // 开辟数组
            StringBuilder[] list = new StringBuilder[numRows];
            for (int i = 0; i < list.length; i++) {
                list[i] = new StringBuilder();
            }
            // status标志向上还是向下走，0向下，1向上
            int status = 0;
            int s_Index = 0;
            int len = s.length(); // 频繁调用.length()可能有损效率
            while (s_Index < len) {
                if (status == 0) {
                    // 注意不要越界了
                    for (int i = 0; i < numRows && s_Index < len; i++) {
                        list[i].append(s.charAt(s_Index++));
                    }
                    // 改变状态
                    status = 1;
                } else {
                    for (int i = numRows - 2; i > 0 && s_Index < len; i--) {
                        list[i].append(s.charAt(s_Index++));
                    }
                    status = 0;
                }
            }
            // 组合最后答案
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < list.length; i++) {
                builder.append(list[i]);
            }
            // 完成
            return builder.toString();
        }
    }
}

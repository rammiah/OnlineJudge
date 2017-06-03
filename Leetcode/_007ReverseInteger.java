package Leetcode;

/**
 * Created by yaning on 17-6-3.
 */
public class _007ReverseInteger {

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.reverse(-2147483648));
    }
    // 反转数字，溢出输出0
    static class Solution {
        public int reverse(int x) {
            long sol = 0;
            long temp = x;
            if (x < 0) {
                temp = -x;
            }
            while (temp > 0) {
                sol *= 10;
                sol += temp % 10;
                temp /= 10;
            }
            // 判断是否溢出，后面那个开始没想起来，我真傻啊。。。
            if (x > 0 && sol > Integer.MAX_VALUE || x < 0 && sol -1 > Integer.MAX_VALUE) {
                return 0;
            }
            if (x < 0) {
                return (int) -sol;
            } else {
                return (int) sol;
            }
        }
    }
}

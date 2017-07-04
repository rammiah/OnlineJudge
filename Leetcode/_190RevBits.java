package Leetcode;

/**
 * Created by yaning on 17-5-30.
 */
public class _190RevBits {

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.reverseBits(43261596));
    }

    static class Solution {
        // you need treat n as an unsigned value
        public int reverseBits(int n) {
            return Integer.reverse(n);
        }
    }
}

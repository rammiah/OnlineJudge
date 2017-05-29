package Leetcode;

/**
 * Created by yaning on 17-5-29.
 */
public class _53MaxSub {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        System.out.println(sol.maxSubArray(arr));
    }

    static class Solution {
        public int maxSubArray(int[] nums) {
            int[] arr = new int[nums.length];
            arr[0] = nums[0];
            int max = -Integer.MAX_VALUE;
            for (int i = 1; i < nums.length; ++i) {
                arr[i] = (arr[i - 1] > 0 ? nums[i] + arr[i - 1] : nums[i]);
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        }
    }
}

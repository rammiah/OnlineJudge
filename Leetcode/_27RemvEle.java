package Leetcode;

/**
 * Created by yaning on 17-5-29.
 */
public class _27RemvEle {

    public static void main(String[] args) {

    }

    static class Solution {
        public int removeElement(int[] nums, int val) {
            int index = 0;
            int t = 0;
            if (nums.length == 0) return 0;
            while (index < nums.length) {
                if (nums[index] != val) {
                    nums[t++] = nums[index];
                }
                ++index;
            }
            return t;
        }
    }

}

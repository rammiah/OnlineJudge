package Leetcode;

/**
 * Created by yaning on 17-5-25.
 */
public class _26RemoveDuplicates {

    public static void main(String[] args){
        Solution sol = new Solution();
        int[] arr = { 1, 1, 2 };
        System.out.println(sol.removeDuplicates(arr));
    }


    static class Solution{
        public int removeDuplicates(int[] nums) {
            int i = nums.length > 0 ? 1 : 0;

            for (int n : nums){
                if (n > nums[i - 1]){
                    nums[i++] = n;
                }
            }
            return i;
        }
    }
}

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int max= 0;
        for (int i = 1; i < nums.length; i++) {
            nums[i] = nums[i] > 0 ? nums[i - 1] + 1 : 0;
            max = Math.max(nums[i], max);
        }

        return max;
    }
}